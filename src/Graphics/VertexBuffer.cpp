#include "VertexBuffer.h"

#include "Renderer.h"

/** @file VertexBuffer.cpp
 *
 * @brief Implementation of VertexBuffer class methods
 *
 * @author Patryk Janiak
 */

using namespace Graphics;

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
  GLCall(glGenBuffers(1, &this->rendererID));
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, this->rendererID));
  GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
  GLCall(glDeleteBuffers(1, &this->rendererID));
}

void VertexBuffer::bind() const
{
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, this->rendererID));
}

void VertexBuffer::unbind() const
{
  GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
