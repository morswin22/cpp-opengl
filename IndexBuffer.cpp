#include "IndexBuffer.h"

#include "Renderer.h"

/** @file IndexBuffer.cpp
 *
 * @brief Implementation of IndexBuffer class methods
 *
 * @author Patryk Janiak
 */

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : count(count)
{
  ASSERT(sizeof(unsigned int) == sizeof(GLuint));

  GLCall(glGenBuffers(1, &this->rendererID));
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->rendererID));
  GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
  GLCall(glDeleteBuffers(1, &this->rendererID));
}

void IndexBuffer::bind() const
{
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->rendererID));
}

void IndexBuffer::unbind() const
{
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
