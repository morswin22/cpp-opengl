#pragma once

#include <memory>
#include <glm/glm.hpp>
#include "../src/Graphics.h"

#include "Test.h"

/** @file TestTexture2D.h
 *
 * @brief Contains TestTexture2D declaration
 *
 * @author Patryk Janiak
 */

namespace Tests {

  /** @brief Test of rendering two objects with textures */
  class TestTexture2D : public Test
  {
    /** @brief Stores objects positions*/
    glm::vec3 translationA, translationB;

    /** @brief Stores VAO of the rendered object */
    std::unique_ptr<Graphics::VertexArray> VAO;

    /** @brief Stores index buffer of the rendered object */
    std::unique_ptr<Graphics::IndexBuffer> indexBuffer;

    /** @brief Stores the shader program */
    std::unique_ptr<Graphics::Shader> shader;

    /** @brief Stores texture of the rendered object */
    std::unique_ptr<Graphics::Texture> texture;

  public:
    /** @brief Default constructor */
    TestTexture2D();

    /** @brief Destructor */
    ~TestTexture2D();

    /** @brief Renders two objects with textures on screen */
    void onRender() override;

    /** @brief Renders position controllers */
    void onImGuiRender() override;
  };


}
