#include "TestGeometry.h"

#include "../src/Geometry.h"
#include "../src/Graphics.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/** @file TestGeometry.cpp
 *
 * @brief Implementation of TestGeometry class methods
 *
 * @author Patryk Janiak
 */

using namespace Tests;

TestGeometry::TestGeometry() : translation(150.0f, 200.0f, 0.0f), scale(50.0f, 50.0f, 1.0f)
{
  Geometry::Point* vertices = new Geometry::Point[3]{ {0.0, 0.0}, {3.0, 0.0}, {0.0, 4.0} };
  this->triangle = std::make_unique<Geometry::Polygon>(vertices, 3);

  float positions[] = {
    vertices[0].getX(), vertices[0].getY(),
    vertices[1].getX(), vertices[1].getY(),
    vertices[2].getX(), vertices[2].getY()
  };

  unsigned int indices[] = {
    0, 1, 2
  };

  this->VAO = std::make_unique<Graphics::VertexArray>();
  Graphics::VertexBuffer vb(positions, 3 * 2 * sizeof(float));

  Graphics::VertexBufferLayout layout;
  layout.push<float>(2);
  this->VAO->addBuffer(vb, layout);

  this->indexBuffer = std::make_unique<Graphics::IndexBuffer>(indices, 3);

  this->shader = std::make_unique<Graphics::Shader>("assets/shaders/SolidColor.shader");
  this->shader->bind();

  this->VAO->unbind();
  vb.unbind();
  this->indexBuffer->unbind();
  this->shader->unbind();
}

void TestGeometry::onRender()
{
  auto& renderer = Graphics::Renderer::get();
  this->shader->bind();

  glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), this->translation), this->scale);
  glm::mat4 mvp = renderer.getProjection() * renderer.getView() * model;
  this->shader->setUniformMat4f("u_MVP", mvp);
  this->shader->setUniform4f("u_Color", 1.0f, 0.0f, 1.0f, 1.0f);

  renderer.draw(*this->VAO, *this->indexBuffer, *this->shader);
}
