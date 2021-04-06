#include "Test.h"

#include <imgui.h>
#include <iostream>

/** @file Test.cpp
 *
 * @brief Implementation of TestMenu class methods
 *
 * @author Patryk Janiak
 */

using namespace Tests;

TestMenu::TestMenu(Test*& currentTestPointer)
  : currentTest(currentTestPointer) 
{
}

TestMenu::~TestMenu() 
{
}

void TestMenu::onImGuiRender()
{
  for (auto& test : this->tests)
  {
    if (ImGui::Button(test.first.c_str()))
      this->currentTest = test.second();
  }
}