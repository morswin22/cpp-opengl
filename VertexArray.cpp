#include "VertexArray.h"

#include <vector>

#include "VertexBufferLayout.h"
#include "Renderer.h"

/** @file VertexArray.cpp
 *
 * @brief Implementation of VertexArray class methods
 *
 * @author Patryk Janiak
 */

VertexArray::VertexArray()
{
  GLCall(glGenVertexArrays(1, &this->rendererID));
}

VertexArray::~VertexArray()
{
  GLCall(glDeleteVertexArrays(1, &this->rendererID));
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
  this->bind();
  vb.bind();
  const auto& elements = layout.getElements();
  unsigned int offset = 0;
  for (unsigned int i = 0; i < elements.size(); i++)
  {
    const auto& element = elements[i];
    GLCall(glEnableVertexAttribArray(i));
    GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*) offset));
    offset += element.count * VertexBufferElement::getSizeOfType(element.type);
  }
}

void VertexArray::bind() const
{
  GLCall(glBindVertexArray(this->rendererID));
}


void VertexArray::unbind() const
{
  GLCall(glBindVertexArray(0));
}