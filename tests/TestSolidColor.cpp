#include "TestSolidColor.h"

#include "../src/Graphics/Renderer.h"
#include "imgui.h"

/** @file TestSolidColor.cpp
 *
 * @brief Implementation of TestSolidColor class methods
 *
 * @author Patryk Janiak
 */

using namespace Tests;

TestSolidColor::TestSolidColor()
  : solidColor { 0.2f, 0.3f, 0.8f, 1.0f }
{
}

TestSolidColor::~TestSolidColor()
{
}

void TestSolidColor::onRender()
{
  GLCall(glClearColor(this->solidColor[0], this->solidColor[1], this->solidColor[2], this->solidColor[3]));
  GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void TestSolidColor::onImGuiRender()
{
  ImGui::ColorEdit4("Solid color", this->solidColor);
}
