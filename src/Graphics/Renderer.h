#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <memory>

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

  /** @brief A struct containing all required data to render */
  struct Renderable
  {
    /** @brief The vertex buffer object */
    std::unique_ptr<VertexArray> VAO;

    /** @brief The index buffer object */
    std::unique_ptr<IndexBuffer> IBO;

    /** @brief The shader program */
    std::unique_ptr<Shader> shader;

    /** @brief Default constructor */
    Renderable() {};

    /** 
     * @brief Main constructor
     * 
     * @param indices A table of indices describing the triangles in VAO
     * @param indicesCount Number of indices
     * @param shaderPath The path to the shader program
     */
    Renderable(unsigned int* indices, int indicesCount, std::string shaderPath);
  };

  /** @brief Main OpenGL handler class */
  class Renderer
  {
    /** @brief GLFW window handle */
    GLFWwindow* window;

    /** @brief The projection matrix */
    glm::mat4 projection;

    /** @brief Mouse position on the screen */
    glm::vec2 mousePosition;

    /** @brief Mouse dragging state */
    bool isMouseDragged;

    /** @brief Flag describing wheter mouse can move the camera */
    bool allowMouseDrag;

    /** @brief Flag describing wheter mouse can zoom in/out the camera */
    bool allowMouseZoom;

    /** @brief The mouse drag origin position */
    glm::vec2 mouseDragOrigin;

    /** @brief The camera position */
    glm::vec3 cameraPosition;

    /** @biref The camera zoom */
    glm::vec3 cameraZoom;

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

    /** @brief Draw using the given Renderable object */
    void draw(const Renderable& object) const;

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

    /** @brief Getter for the view matrix */
    inline glm::mat4 getView() const { return this->view; }

    /** @brief Setter for the camera position */
    void setCameraPosition(float x, float y);

    /** @brief Setter for the camera zoom */
    void setCameraZoom(float z);

    /** @brief Setter for the camera zoom */
    void setCameraZoom(float zx, float zy);

    /** @brief Setter for the mouse camera move flag */
    void setAllowMouseDrag(bool value);

    /** @brief Setter for the mouse camera zoom flag */
    void setAllowMouseZoom(bool value);

    /** @brief Method that resets the camera to default */
    void resetCamera();

    /** @brief Handle the scroll event from OpenGL */
    void handleScroll(double xoffset, double yoffset);

    /** @brief Handle the mouse move event from OpenGL */
    void handleMousePosition(double xpos, double ypos);

    /** @brief Handle the mouse buttons events from OpenGL */
    void handleMouseButtons(int button, int action, int mods);

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