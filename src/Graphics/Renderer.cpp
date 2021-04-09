#include "Renderer.h"

#include <iostream>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/** @file Renderer.cpp
 *
 * @brief Implementation of Renderer class methods
 *
 * @author Patryk Janiak
 */

using namespace Graphics;

void GLClearError()
{
  while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
  while (GLenum error = glGetError())
  {
    std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << "\n";
    return false;
  }
  return true;
}

Renderable::Renderable(unsigned int* indices, int indicesCount, std::string shaderPath)
{
  this->VAO = std::make_unique<VertexArray>();
  this->IBO = std::make_unique<IndexBuffer>(indices, indicesCount);
  this->shader = std::make_unique<Shader>(shaderPath);
}

inline void receiveScroll(GLFWwindow* window, double xoffset, double yoffset)
{
  Renderer::get().handleScroll(xoffset, yoffset);
}

inline void receiveMousePosition(GLFWwindow* window, double xpos, double ypos)
{
  Renderer::get().handleMousePosition(xpos, ypos);
}

inline void receiveMouseButtons(GLFWwindow* window, int button, int action, int mods)
{
  Renderer::get().handleMouseButtons(button, action, mods);
}

Renderer::Renderer()
  : cameraPosition(0.0f, 0.0f, 0.0f), cameraZoom(1.0f, 1.0f, 1.0f), mousePosition(0.0f, 0.0f), isMouseDragged(false), allowMouseDrag(false), mouseDragOrigin(0.0f, 0.0f)
{
  if (!glfwInit())
    throw "GLFW initialization error";

  this->window = glfwCreateWindow(100, 100, "Default", NULL, NULL);
  if (!this->window)
  {
    glfwTerminate();
    throw "Window creation error";
  }

  glfwMakeContextCurrent(this->window);
  glfwSwapInterval(1);

  if (glewInit() != GLEW_OK)
    throw "GLEW initialization error";

  GLCall(glEnable(GL_BLEND));
  GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

  this->projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  this->view = glm::scale(glm::translate(glm::mat4(1.0f), this->cameraPosition), this->cameraZoom);

  glfwSetScrollCallback(this->window, receiveScroll);
  glfwSetCursorPosCallback(this->window, receiveMousePosition);
  glfwSetMouseButtonCallback(this->window, receiveMouseButtons);

  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(this->window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  this->lastTime = glfwGetTime();
}

Renderer::~Renderer()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

void Renderer::setTitle(const char* title)
{
  glfwSetWindowTitle(this->window, title);
}

void Renderer::setSize(int width, int height)
{
  glfwSetWindowSize(this->window, width, height);
  GLCall(glViewport(0, 0, width, height));
  this->projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
}

void Renderer::clear() const
{
  GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
  GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
  shader.bind();
  va.bind();
  ib.bind();
  GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::draw(const Renderable& object) const
{
  object.shader->bind();
  object.VAO->bind();
  object.IBO->bind();
  GLCall(glDrawElements(GL_TRIANGLES, object.IBO->getCount(), GL_UNSIGNED_INT, nullptr));
}

const unsigned char* Renderer::getVersion() const
{
  return glGetString(GL_VERSION);
}

void Renderer::setCameraPosition(float x, float y)
{
  this->cameraPosition.x = x;
  this->cameraPosition.y = y;
  this->view = glm::scale(glm::translate(glm::mat4(1.0f), this->cameraPosition), this->cameraZoom);
}

void Renderer::setCameraZoom(float z)
{
  this->cameraZoom.x = z;
  this->cameraZoom.y = z;
  this->view = glm::scale(glm::translate(glm::mat4(1.0f), this->cameraPosition), this->cameraZoom);
}

void Renderer::setCameraZoom(float zx, float zy)
{
  this->cameraZoom.x = zx;
  this->cameraZoom.y = zy;
  this->view = glm::scale(glm::translate(glm::mat4(1.0f), this->cameraPosition), this->cameraZoom);
}

void Renderer::handleScroll(double xoffset, double yoffset)
{
  if (!this->allowMouseZoom)
    return;
  this->cameraZoom.x *= (float)(yoffset * 0.375 + 1.125);
  this->cameraZoom.y *= (float)(yoffset * 0.375 + 1.125);
  this->view = glm::scale(glm::translate(glm::mat4(1.0f), this->cameraPosition), this->cameraZoom);
}

void Renderer::handleMousePosition(double xpos, double ypos)
{
  this->mousePosition.x = (float) xpos;
  this->mousePosition.y = (float) (540 - ypos);
  if (this->allowMouseDrag && this->isMouseDragged)
  {
    glm::vec3 tempPosition(this->cameraPosition.x + (this->mousePosition.x - this->mouseDragOrigin.x), this->cameraPosition.y + (this->mousePosition.y - this->mouseDragOrigin.y), 1.0f);
    this->view = glm::scale(glm::translate(glm::mat4(1.0f), tempPosition), this->cameraZoom);
  }
}

void Renderer::handleMouseButtons(int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_LEFT)
  {
    if (action == GLFW_PRESS)
    {
      if (mods & GLFW_MOD_CONTROL)
      {
        if (this->allowMouseDrag)
        {
          this->isMouseDragged = true;
          this->mouseDragOrigin.x = this->mousePosition.x;
          this->mouseDragOrigin.y = this->mousePosition.y;
        }
      }
    }
    else
    {
      if (this->allowMouseDrag && this->isMouseDragged)
      {
        this->isMouseDragged = false;
        this->cameraPosition.x += this->mousePosition.x - this->mouseDragOrigin.x;
        this->cameraPosition.y += this->mousePosition.y - this->mouseDragOrigin.y;
      }
    }
  }
}

void Renderer::setAllowMouseDrag(bool value)
{
  this->allowMouseDrag = value;
}

void Renderer::setAllowMouseZoom(bool value)
{
  this->allowMouseZoom = value;
}


void Renderer::resetCamera()
{
  this->setCameraPosition(0.0f, 0.0f);
  this->setCameraZoom(1.0f);
  this->isMouseDragged = false;
  this->allowMouseDrag = false;
  this->allowMouseZoom = false;
}

double Renderer::getDeltaTime()
{
  double temp = this->lastTime;
  this->lastTime = glfwGetTime();
  return this->lastTime - temp;
}

bool Renderer::isRunning() const
{
  return !glfwWindowShouldClose(this->window);
}

void Renderer::ImGuiBeginFrame() const
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void Renderer::ImGuiEndFrame() const
{
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Renderer::swapBuffers() const
{
  glfwSwapBuffers(this->window);
}

void Renderer::pollEvents() const
{
  glfwPollEvents();
}
