#pragma once

#include <vector>
#include "Renderer.h"

/** @file VertexBufferLayout.h
 *
 * @brief Contains a VertexBufferLayout class declaration and a VertexBufferElement declaration
 *
 * @author Patryk Janiak
 */

/** @brief Provides storage for required information to lay out the VertexBuffer data */
struct VertexBufferElement
{
  /** @brief Stores OpenGL's type */
  unsigned int type;

  /** @brief Stores number of datapoints */
  unsigned int count;

  /** @brief Stores OpenGL's normalized flag */
  unsigned char normalized;

  /**
   * @brief Getter for size of OpenGL's types
   * 
   * @param type an OpenGL's type
   * @return unsigned int size in bytes
   */
  static unsigned int getSizeOfType(unsigned int type);
};

/** @brief Class that organizes VertexBuffer data into OpenGL types */
class VertexBufferLayout
{
  /** @brief Stores layout elements */
  std::vector<VertexBufferElement> elements;

  /** @brief Keeps track of current stride value */
  unsigned int stride;

  public:
    /** @brief Default constructor */
    VertexBufferLayout();

    /** @brief Base declaration for push method */
    template<typename T>
    void push(unsigned int count);

    /**
     * @brief Method that pushes a new element
     * 
     * @tparam float type of the stored data
     * @param count number of stored datapoints
     */
    template<>
    void push<float>(unsigned int count);

    /**
     * @brief Method that pushes a new element
     * 
     * @tparam unsigned int type of the stored data
     * @param count number of stored datapoints
     */
    template<>
    void push<unsigned int>(unsigned int count);

    /**
     * @brief Method that pushes a new element
     * 
     * @tparam unsigned char type of the stored data
     * @param count number of stored datapoints
     */
    template<>
    void push<unsigned char>(unsigned int count);

    /** @brief Getter for elements array */
    inline const std::vector<VertexBufferElement>& getElements() const { return this->elements; }

    /** @brief Getter for stride value */
    inline unsigned int getStride() const { return this->stride; }
};

