#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

/** @file Renderer.h
 *
 * @brief Contains a Renderer class declaration, GLCall and ASSERT macros
 *
 * @author Patryk Janiak
 */

namespace Graphics {

  /** @brief This function removes all pending OpenGL's errors */
  void GLClearError();

  /**
   * @brief This function prints all pending OpenGL's errors
   *
   * @param function the executed code
   * @param file the file with that code
   * @param line the line with that code
   * @return true when there are no errors
   */
  bool GLLogCall(const char* function, const char* file, int line);

  /** @brief Main OpenGL handler class */
  class Renderer
  {
    /** @brief GLFW window handle */
    GLFWwindow* window;

  public:
    /**
     * @brief Main constructor
     *
     * @param width window's width
     * @param height window's height
     * @param title window's tittle
     */
    Renderer(int width, int height, const char* title);

    /** @brief Destructor of Renderer class */
    ~Renderer();

    /** @brief Clears the window */
    void clear() const;

    /**
     * @brief Draw using the given VertexArray, IndexBuffer and the specified Shader program
     *
     * @param va handle for the OpenGL's vertex array
     * @param ib handle for the OpenGL's index buffer
     * @param shader handle for the OpenGL's shader program
     */
    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

    /**
     * @brief Getter for the driver version
     *
     * @return const unsigned* the driver version
     */
    const unsigned char* getVersion() const;

    /**
     * @brief Getter for the window open state
     *
     * @return true when a new draw should happen
     */
    bool isRunning() const;

    /** @brief Handle for GLWF swapBuffers */
    void swapBuffers() const;

    /** @brief Handle for GLWF pollEvents */
    void pollEvents() const;

  };

}