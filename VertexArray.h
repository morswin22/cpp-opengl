#pragma once

#include "VertexBuffer.h"

/** @file VertexArray.h
 *
 * @brief Contains a VertexArray class declaration
 *
 * @author Patryk Janiak
 */

// Forward declaration of VertexBufferLayout
class VertexBufferLayout;

/** @brief Handles OpenGL's vertex array */
class VertexArray
{
  /** @brief Buffer id */
  unsigned int rendererID;

  public:
    /** @brief Default constructor */
    VertexArray();

    /** @brief Destructor of VertexArray class */
    ~VertexArray();

    /**
     * @brief Adds a vertex buffer to the vertex array
     * 
     * @param vb handle for the vertex buffer
     * @param layout handle for the layout
     */
    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    /**  @brief A method to bind the vertex array */
    void bind() const;

    /**  @brief A method to unbind the vertex array */
    void unbind() const;
};

