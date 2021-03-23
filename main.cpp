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
  Physics::Polygon p{ new Physics::Point[3]{{0.0, 0.0}, {3.0, 0.0}, {0.0, 4.0}}, 3 };

  std::cout << "Obwód: " << p.getPerimeter() << "\n";
  std::cout << "Pole: " << p.getConvexArea() << "\n";

  // p.setVertices(new Point[3]{{2.0, 4.0}, {3.0, -8.0}, {1.0, 2.0}}, 3);
  std::cout << "Pole dla innych punktów: " << p.getArea() << "\n";
}

int main()
{
  f();

  return 0;
  // Point p1 = Point(5.0, 0.6);
  // p1.print();

  // p1.setX(10.0);
  // p1.print();

  // Point p2;
  // p2.print();

  // std::cout << "Odleg³oœæ od p1 do p2: " << p1.getDistance(p2) << "\n";

  // p2.setX(3.7);
  // p2.setY(6.1);
  // p2.print();

  // Point p3 = p2;
  // p3.print();

  // Point p4 = p1.add(p2);
  // std::cout << "p4 = p1 + p2: ";
  // p4.print();

  // Point p5 = p4.subtract(p1);
  // std::cout << "p5 = p4 - p1: ";
  // p5.print();
}