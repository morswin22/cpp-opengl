#include "TestTexture2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>

#include "../src/Graphics.h"

/** @file TestTexture2D.cpp
 *
 * @brief Implementation of TestTexture2D class methods
 *
 * @author Patryk Janiak
 */

using namespace Tests;

TestTexture2D::TestTexture2D()
  : translationA(0.0f, 0.0f, 0.0f), translationB(300.0f, 300.0f, 0.0f)
{
  float positions[] = {
    -50.0f, -50.0f, 0.0f, 0.0f,
     50.0f, -50.0f, 1.0f, 0.0f,
     50.0f,  50.0f, 1.0f, 1.0f,
    -50.0f,  50.0f, 0.0f, 1.0f
  };

  unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0
  };

  this->VAO = std::make_unique<Graphics::VertexArray>();
  Graphics::VertexBuffer vb(positions, 4 * 4 * sizeof(float));

  Graphics::VertexBufferLayout layout;
  layout.push<float>(2);
  layout.push<float>(2);
  this->VAO->addBuffer(vb, layout);

  this->indexBuffer = std::make_unique<Graphics::IndexBuffer>(indices, 6);

  this->shader = std::make_unique<Graphics::Shader>("assets/shaders/Basic.shader");
  this->shader->bind();

  this->texture = std::make_unique<Graphics::Texture>("assets/textures/wooden_log.png");
  this->texture->bind();
  this->shader->setUniform1i("u_Texture", 0);

  this->VAO->unbind();
  vb.unbind();
  this->indexBuffer->unbind();
  this->shader->unbind();
}

TestTexture2D::~TestTexture2D()
{
}

void TestTexture2D::onRender()
{
  auto& renderer = Graphics::Renderer::get();
  this->shader->bind();

  {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), this->translationA);
    glm::mat4 mvp = renderer.getProjection() * renderer.getView() * model;
    this->shader->setUniformMat4f("u_MVP", mvp);

    renderer.draw(*this->VAO, *this->indexBuffer, *this->shader);
  };

  {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), this->translationB);
    glm::mat4 mvp = renderer.getProjection() * renderer.getView() * model;
    this->shader->setUniformMat4f("u_MVP", mvp);

    renderer.draw(*this->VAO, *this->indexBuffer, *this->shader);
  };
}

void TestTexture2D::onImGuiRender()
{
  ImGui::SliderFloat("dx", &this->translationA.x, 0.0f, 960.0f);
  ImGui::SliderFloat("dy", &this->translationA.y, 0.0f, 540.0f);
}
