#pragma once

/** @file IndexBuffer.h
 *
 * @brief Contains a IndexBuffer class declaration
 *
 * @author Patryk Janiak
 */

namespace Graphics {

  /** @brief Handles OpenGL's index buffer */
  class IndexBuffer
  {
    /** @brief Buffer id */
    unsigned int rendererID;

    /** @brief Number of indices */
    unsigned int count;

  public:
    /**
     * @brief Main constructor
     *
     * @param data an array containing the indices
     * @param count number of indices
     */
    IndexBuffer(const unsigned int* data, unsigned int count);

    /**  @brief Destructor of the IndexBuffer class */
    ~IndexBuffer();

    /**  @brief A method to bind the index buffer */
    void bind() const;

    /**  @brief A method to unbind the index buffer */
    void unbind() const;

    /**  @brief Getter for the number of indices */
    inline unsigned int getCount() const { return this->count; }
  };

}