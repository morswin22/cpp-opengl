#pragma once

/** @file VertexBuffer.h
 *
 * @brief Contains a VertexBuffer class declaration
 *
 * @author Patryk Janiak
 */

/** @brief Handles OpenGL's vertex buffer */
class VertexBuffer
{
  /** @brief Buffer id */
  unsigned int rendererID;
  
  public:
    /**
     * @brief Main constructor
     * 
     * @param data an array containing the vertices 
     * @param size byte size of the data
     */
    VertexBuffer(const void* data, unsigned int size);

    /** @brief Destructor of VertexBuffer class */
    ~VertexBuffer();

    /**  @brief A method to bind the vertex buffer */
    void bind() const;

    /**  @brief A method to unbind the vertex buffer */
    void unbind() const;
};

