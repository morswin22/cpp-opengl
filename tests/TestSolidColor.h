#pragma once

#include "Test.h"

/** @file TestSolidColor.h
 *
 * @brief Contains TestSolidColor declaration
 *
 * @author Patryk Janiak
 */

namespace Tests {

  /** @brief Test of rendering solid color */
  class TestSolidColor : public Test
  {
    /** @brief Array of rgb color values */
    float solidColor[4];

  public:
    /** @brief Default constructor */
    TestSolidColor();

    /** @brief Destructor */
    ~TestSolidColor();

    /** @brief Renders solid color on screen */
    void onRender() override;

    /** @brief Renders color controllers */
    void onImGuiRender() override;
  };


}

