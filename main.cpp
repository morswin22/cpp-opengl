/** @file main.cpp
 *
 * @brief C++ and OpenGL test program code
 *
 * @author Patryk Janiak
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>

#include "src/Geometry.h"
#include "src/Graphics.h"

void f()
{
  Geometry::Polygon p{ new Geometry::Point[3]{{0.0, 0.0}, {3.0, 0.0}, {0.0, 4.0}}, 3 };

  std::cout << p << "\n";
  std::cout << "Perimeter: " << p.getPerimeter() << "\n";
  std::cout << "Convex area: " << p.getConvexArea() << "\n";

  p.setVertices(new Geometry::Point[3]{{2.0, 4.0}, {3.0, -8.0}, {1.0, 2.0}}, 3);
  std::cout << "Shoelace area for a different set of vertices: " << p.getArea() << "\n";
}

int main()
{
  f();

  Graphics::Renderer renderer(960, 540, "Test");
  std::cout << "Version: " << renderer.getVersion() << "\n";

  {
    float positions[] = {
        0.0f,   0.0f, 0.0f, 0.0f,
      100.0f,   0.0f, 1.0f, 0.0f,
      100.0f, 100.0f, 1.0f, 1.0f,
        0.0f, 100.0f, 0.0f, 1.0f
    };

    unsigned int indices[] = {
      0, 1, 2,
      2, 3, 0
    };

    Graphics::VertexArray va;
    Graphics::VertexBuffer vb(positions, 4 * 4 * sizeof(float));

    Graphics::VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);
    va.addBuffer(vb, layout);

    Graphics::IndexBuffer ib(indices, 6);

    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

    Graphics::Shader shader("assets/shaders/Basic.shader");
    shader.bind();

    Graphics::Texture texture("assets/textures/wooden_log.png");
    texture.bind();
    shader.setUniform1i("u_Texture", 0);

    va.unbind();
    shader.unbind();
    vb.unbind();
    ib.unbind();

    float r = 0.0f;
    float increment = 0.05f;

    glm::vec3 translation(0.0f, 0.0f, 0.0f);

    while (renderer.isRunning())
    {
      renderer.clear();
      renderer.ImGuiBeginFrame();

      shader.bind();

      glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
      glm::mat4 mvp = proj * view * model;
      shader.setUniformMat4f("u_MVP", mvp);

      renderer.draw(va, ib, shader);

      if (r > 1.0f)
        increment = -0.05f;
      else if (r < 0.0f)
        increment = 0.05f;

      r += increment;

      {
        ImGui::Begin("Move the log!");
        ImGui::SliderFloat("dx", &translation.x, 0.0f, 960.0f);
        ImGui::SliderFloat("dy", &translation.y, 0.0f, 540.0f);
        ImGui::End();
      };

      renderer.ImGuiEndFrame();
      renderer.swapBuffers();
      renderer.pollEvents();
    }
  };

  return 0;
}