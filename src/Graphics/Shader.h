#pragma once

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

/** @file Shader.h
 *
 * @brief Contains a Shader class declaration and a ShaderProgramSource struct declaration
 *
 * @author Patryk Janiak
 */

namespace Graphics {

  /** @brief Contains vertex shader and fragment shader source code */
  struct ShaderProgramSource
  {
    /** @brief Vertex shader source code */
    std::string vertexSource;

    /** @brief Fragment shader source code */
    std::string fragmentSource;
  };

  /** @brief Creates a shader program to run on the GPU */
  class Shader
  {
    /** @brief Path to the file containing shader source code */
    std::string filepath;

    /** @brief Shader id */
    unsigned int rendererID;

    /** @brief Variables' locations cache */
    std::unordered_map<std::string, int> locationCache;

    /**
     * @brief Variable location getter
     *
     * @param name variable's name
     * @return int location of the variable
     */
    int getUniformLocation(const std::string& name);

    /**
     * @brief Method that reads shader source code and splits it into vertex and fragment source
     *
     * @return ShaderProgramSource containing vertex shader and fragment shader source code
     */
    ShaderProgramSource parseShader();

    /**
     * @brief Method that compiles an vertex or fragment shader
     *
     * @param type can be either vertex or fragment shader
     * @param source a string containing shader source code
     * @return unsigned int shader's id
     */
    unsigned int compileShader(unsigned int type, const std::string& source);

    /**
     * @brief Method that creates a shader from it's source code
     *
     * @param vertexShader vertex shader's source code
     * @param fragmentShader fragment shader's source code
     * @return unsigned int shader program's id
     */
    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

  public:
    /** @brief Default constructor */
    Shader();

    /**
     * @brief Main constructor
     *
     * @param filepath path to the file containing shader source code
     */
    Shader(const std::string& filepath);

    /** @brief Destructor of Shader class */
    ~Shader();

    /**  @brief A method to bind the shader */
    void bind() const;

    /**  @brief A method to unbind the shader */
    void unbind() const;

    /**
     * @brief Setter of the uniform variable with 1 int
     *
     * @param name variable's name
     * @param value the value to be stored
     */
    void setUniform1i(const std::string& name, int value);

    /**
     * @brief Setter of the uniform variable with 1 float
     *
     * @param name variable's name
     * @param value the value to be stored
     */
    void setUniform1f(const std::string& name, float value);

    /**
     * @brief Setter of the uniform variable with 4 floats
     *
     * @param name variable's name
     * @param v0 first value
     * @param v1 second value
     * @param v2 third value
     * @param v3 forth value
     */
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

    /**
     * @brief Setter of the uniform matrix with 4 floats
     *
     * @param name variable's name
     * @param matrix the value to be stored
     */
    void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
  };

}