#include "Texture.h"

#include "../../vendor/stb_image.h"

/** @file Texture.cpp
 *
 * @brief Implementation of Texture class methods
 *
 * @author Patryk Janiak
 */

Graphics::Texture::Texture(const std::string& path)
  : rendererID(0), filepath(path), localBuffer(nullptr), width(0), height(0), BPP(0)
{
  stbi_set_flip_vertically_on_load(1);
  this->localBuffer = stbi_load(path.c_str(), &this->width, &this->height, &this->BPP, 4);

  GLCall(glGenTextures(1, &this->rendererID));
  GLCall(glBindTexture(GL_TEXTURE_2D, this->rendererID));

  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

  GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->localBuffer));
  GLCall(glBindTexture(GL_TEXTURE_2D, 0));

  if (this->localBuffer)
    stbi_image_free(this->localBuffer);
}

Graphics::Texture::~Texture()
{
  GLCall(glDeleteTextures(1, &this->rendererID));
}

void Graphics::Texture::bind(unsigned int slot) const
{
  GLCall(glActiveTexture(GL_TEXTURE0 + slot));
  GLCall(glBindTexture(GL_TEXTURE_2D, this->rendererID));
}

void Graphics::Texture::unbind() const
{
  GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

inline int Graphics::Texture::getWidth() const
{
  return this->width;
}

inline int Graphics::Texture::getHeight() const
{
  return this->height;
}
