#pragma once

#include "Renderer.h"

/** @file Texture.h
 *
 * @brief Contains Texture class declaration
 *
 * @author Patryk Janiak
 */

namespace Graphics {

  /** @brief Loads a texture from file into a buffer */
  class Texture
  {
    /** @brief Shader id */
    unsigned int rendererID;

    /** @brief Path to the file containing shader source code */
    std::string filepath;

    /** @brief Stores the loaded texture */
    unsigned char* localBuffer;

    /** @brief Width of the texture */
    int width;

    /** @brief Height of the texture */
    int height;

    /** @brief Bits per pixel of the texture */
    int BPP;

  public:
    /** 
     * @brief Main constructor
     * 
     * @param path A path to the texture file
     */
    Texture(const std::string& path);

    /** @brief Destructor of Texture class */
    ~Texture();

    /** 
     * @brief A method to bind the shader 
     * 
     * @param slot The texture slot in memory
     */
    void bind(unsigned int slot = 0) const;

    /** @brief A method to unbind the shader */
    void unbind() const;

    /** @brief Getter for width of the texture */
    inline int getWidth() const;

    /** @brief Getter for height of the texture */
    inline int getHeight() const;
  };

}