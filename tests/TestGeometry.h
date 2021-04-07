#pragma once

#include "Test.h"
#include "../src/Geometry.h"
#include "../src/Graphics.h"
#include <memory>
#include <glm/glm.hpp>

/** @file TestGeometry.h
 *
 * @brief Contains TestGeometry declaration
 *
 * @author Patryk Janiak
 */

namespace Tests {

  /** @brief Test of rendering a Polygon from Geometry */
  class TestGeometry : public Test
  {
    /** @brief Stores the triangle */
    std::unique_ptr<Geometry::Polygon> triangle;

    /** @brief Stores object position */
    glm::vec3 translation;

    /** @biref Stores object scale */
    glm::vec3 scale;

    /** @brief Stores VAO of the rendered object */
    std::unique_ptr<Graphics::VertexArray> VAO;

    /** @brief Stores index buffer of the rendered object */
    std::unique_ptr<Graphics::IndexBuffer> indexBuffer;

    /** @brief Stores the shader program */
    std::unique_ptr<Graphics::Shader> shader;

  public:
    /** @brief Default constructor */
    TestGeometry();

    /** @brief Renders a triangle */
    void onRender() override;
  };

}

