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

TestGeometry::TestGeometry()
{
  Geometry::Point* vertices = nullptr;

  vertices = new Geometry::Point[3]{ {0.0, 0.0}, {3.0, 0.0}, {0.0, 4.0} };
  this->triangle = std::make_unique<Geometry::Polygon>(vertices, 3);
  this->renderableTriangle = this->triangle->getRenderable("assets/shaders/SolidColor.shader");
  delete[] vertices;

  vertices = new Geometry::Point[5]{ {-2.0, -1.0}, {-1.0, -3.0}, {-3.0, -4.0}, {-4.0, -3.0}, {-4.0, -2.0} };
  this->complexShape = std::make_unique<Geometry::Polygon>(vertices, 5);
  this->renderableComplexShape = this->complexShape->getRenderable("assets/shaders/SolidColor.shader");
  delete[] vertices;

  auto& renderer = Graphics::Renderer::get();
  renderer.setCameraPosition(480.0f, 270.0f);
  renderer.setCameraZoom(50.0f);
}

void TestGeometry::onRender()
{
  auto& renderer = Graphics::Renderer::get();
  
  {
    this->renderableTriangle.shader->bind();

    glm::mat4 mvp = renderer.getProjection() * renderer.getView();
    this->renderableTriangle.shader->setUniformMat4f("u_MVP", mvp);
    this->renderableTriangle.shader->setUniform4f("u_Color", 1.0f, 0.0f, 1.0f, 1.0f);

    renderer.draw(this->renderableTriangle);
  }

  {
    this->renderableComplexShape.shader->bind();

    glm::mat4 mvp = renderer.getProjection() * renderer.getView();
    this->renderableComplexShape.shader->setUniformMat4f("u_MVP", mvp);
    this->renderableComplexShape.shader->setUniform4f("u_Color", 0.75f, 1.0f, 0.0f, 1.0f);

    renderer.draw(this->renderableComplexShape);
  }
}
