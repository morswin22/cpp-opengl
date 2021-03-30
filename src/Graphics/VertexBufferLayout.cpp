#include "VertexBufferLayout.h"

/** @file VertexBufferLayout.cpp
 *
 * @brief Implementation of VertexBufferLayout class methods and the VertexBufferElement
 *
 * @author Patryk Janiak
 */

using namespace Graphics;

unsigned int VertexBufferElement::getSizeOfType(unsigned int type) {
  switch (type)
  {
  case GL_FLOAT:         return 4;
  case GL_UNSIGNED_INT:  return 4;
  case GL_UNSIGNED_BYTE: return 1;
  }
  ASSERT(false);
  return 0;
}

VertexBufferLayout::VertexBufferLayout() : stride(0) {}

template<typename T>
void VertexBufferLayout::push(unsigned int count)
{
  static_assert(false);
}

template<>
void VertexBufferLayout::push<float>(unsigned int count)
{
  this->elements.push_back({ GL_FLOAT, count, GL_FALSE });
  this->stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count)
{
  this->elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
  this->stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count)
{
  this->elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
  this->stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
}
