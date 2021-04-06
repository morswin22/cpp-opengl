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

Renderer::Renderer()
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

  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(this->window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  this->projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  this->view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

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

const unsigned char* Renderer::getVersion() const
{
  return glGetString(GL_VERSION);
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

void Graphics::Renderer::ImGuiBeginFrame() const
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void Graphics::Renderer::ImGuiEndFrame() const
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
