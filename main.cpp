/** @file main.cpp
 *
 * @brief C++ and OpenGL test program code
 *
 * @author Patryk Janiak
 */

#include "Polygon.h"
#include <iostream>

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

  return 0;
}