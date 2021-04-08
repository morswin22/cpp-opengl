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

    /** @brief Stores the renderable triangle */
    Graphics::Renderable renderableTriangle;

    /** @brief Stores the complex shape */
    std::unique_ptr<Geometry::Polygon> complexShape;

    /** @brief Stores the renderable complex shape */
    Graphics::Renderable renderableComplexShape;

  public:
    /** @brief Default constructor */
    TestGeometry();

    /** @brief Renders a triangle */
    void onRender() override;
  };

}

