#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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

namespace Graphics {

  /** @brief Main OpenGL handler class */
  class Renderer
  {
    /** @brief GLFW window handle */
    GLFWwindow* window;

    /** @brief The projection matrix */
    glm::mat4 projection;

    /** @brief The view matrix */
    glm::mat4 view;

    /** @brief Timestamp of the last frame */
    double lastTime;

    /** @brief Hidden default constructor */
    Renderer();

  public:
    /** @brief Destructor of Renderer class */
    ~Renderer();

    /** @brief Singleton getter */
    static Renderer& get()
    {
      static Renderer instance;
      return instance;
    }

    /**
     * @brief Title setter
     *
     * @param title window's tittle
     */
    void setTitle(const char* title);

    /**
     * @brief Size setter
     *
     * @param width window's width
     * @param height window's height
     */
    void setSize(int width, int height);

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

    /** @brief Getter for the time elapsed since last frame */
    double getDeltaTime();

    /** @biref Getter for the projection matrix */
    inline glm::mat4 getProjection() const { return this->projection; }

    /** @biref Getter for the view matrix */
    inline glm::mat4 getView() const { return this->view; }

    /**
     * @brief Getter for the window open state
     *
     * @return true when a new draw should happen
     */
    bool isRunning() const;

    /** @brief Handle for ImGui new frame */
    void ImGuiBeginFrame() const;

    /** @brief Handle for ImGui render */
    void ImGuiEndFrame() const;

    /** @brief Handle for GLWF swapBuffers */
    void swapBuffers() const;

    /** @brief Handle for GLWF pollEvents */
    void pollEvents() const;

  };

}