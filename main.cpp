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

#include <imgui.h>

#include "src/Geometry.h"
#include "src/Graphics.h"

#include "tests/Test.h"
#include "tests/TestSolidColor.h"
#include "tests/TestTexture2D.h"
#include "tests/TestGeometry.h"

int main()
{
  auto& renderer = Graphics::Renderer::get();
  renderer.setSize(960, 540);
  renderer.setTitle("C++ OpenGL");

  std::cout << "Version: " << renderer.getVersion() << "\n";

  {
    Tests::Test* currentTest = nullptr;
    Tests::TestMenu* testMenu = new Tests::TestMenu(currentTest);
    currentTest = testMenu;

    testMenu->registerTest<Tests::TestSolidColor>("Solid color");
    testMenu->registerTest<Tests::TestTexture2D>("2D texture");
    testMenu->registerTest<Tests::TestGeometry>("Geometry");

    while (renderer.isRunning())
    {
      renderer.clear();
      renderer.ImGuiBeginFrame();

      if (currentTest)
      {
        currentTest->onUpdate(renderer.getDeltaTime());
        currentTest->onRender();
        ImGui::Begin("Dashboard");
        if (currentTest != testMenu && ImGui::Button("Back to menu"))
        {
          delete currentTest;
          currentTest = testMenu;
        }
        currentTest->onImGuiRender();
        ImGui::End();
      }

      renderer.ImGuiEndFrame();
      renderer.swapBuffers();
      renderer.pollEvents();
    }

    if (testMenu != currentTest)
      delete testMenu;
    delete currentTest;
  };

  return 0;
}