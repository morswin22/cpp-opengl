#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>

/** @file Test.h
 *
 * @brief Contains Test and TestMenu declarations
 *
 * @author Patryk Janiak
 */

namespace Tests {

  /** @brief Base class for testing */
  class Test
  {
  public:
    /** @brief Default constructor */
    Test() {}

    /** @brief Destructor */
    virtual ~Test() {}

    /** 
     * @brief This method gets called before the render 
     * 
     * @param deltaTime amount of elapsed time since last render
     */
    virtual void onUpdate(float deltaTime) {}

    /** @brief This method gets called after update */
    virtual void onRender() {}

    /** @brief This method gets called after render */
    virtual void onImGuiRender() {}
  };

  /** @brief Menu with tests */
  class TestMenu : public Test
  {
    /** @brief Reference to the pointer of the current test */
    Test*& currentTest;

    /** @brief List of pairs of test titles and test classes */
    std::vector<std::pair<std::string, std::function<Test* ()>>> tests;

  public:
    /** 
     * @brief Main constructor
     * 
     * @param currentTestPointer a reference to the pointer of the current test
     */
    TestMenu(Test*& currentTestPointer);

    /** @brief Destructor */
    virtual ~TestMenu();

    /** @brief Displays tests to select */
    void onImGuiRender() override;

    /** @brief Method to register new tests */
    template<typename T>
    void registerTest(const std::string& name)
    {
      std::cout << "Registered test: " << name << '\n';
      this->tests.push_back(std::make_pair(name, []() { return new T(); }));
    }
  };

}


