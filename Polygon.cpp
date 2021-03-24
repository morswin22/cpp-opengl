#include "Polygon.h"
#include <iostream>
#include <math.h>

/** @file Polygon.cpp
 *
 * @brief Implementation of Polygon class methods
 *
 * @author Patryk Janiak
 */

Physics::Polygon::Polygon()
{
  count = 0;
  vertices = nullptr;
}

Physics::Polygon::Polygon(Point* _vertices, unsigned int _count)
{
  count = _count;
  vertices = new Point[count];
  for (int i = 0; i < count; i++)
  {
    vertices[i] = _vertices[i];
  }
}

Physics::Polygon::Polygon(const Polygon& _p)
{
  count = _p.count;
  vertices = new Point[count];
  for (int i = 0; i < count; i++)
  {
    vertices[i] = _p.vertices[i];
  }
}

Physics::Polygon::~Polygon()
{
  delete[] vertices;
}

void Physics::Polygon::setVertices(Point* _vertices, int _count)
{
  delete[] vertices;
  count = _count;
  vertices = new Point[count];
  for (int i = 0; i < count; i++)
  {
    vertices[i] = _vertices[i];
  }
}

void Physics::Polygon::changeVertex(int i, double x, double y)
{
  vertices[i].setX(x);
  vertices[i].setY(y);
}

void Physics::Polygon::setCount(int n)
{
  delete[] vertices;
  count = n;
  vertices = new Point[count];
}

double Physics::Polygon::getPerimeter()
{
  if (count == 0)
    return 0.0;
  double perimeter = vertices[0].getDistance(vertices[count - 1]);
  for (int i = 1; i < count; i++)
  {
    perimeter += vertices[i].getDistance(vertices[i - 1]);
  }
  return perimeter;
}

double Physics::Polygon::getTriangleArea(Point p1, Point p2, Point p3)
{
  // Heron's formula
  double a = p1.getDistance(p2);
  double b = p2.getDistance(p3);
  double c = p3.getDistance(p1);
  double p = 0.5 * (a + b + c);
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Physics::Polygon::getConvexArea()
{
  // Wielok¹t musi byæ wypuk³y
  double area{ 0.0 };
  for (int i = 2; i < count; i++)
  {
    area += getTriangleArea(vertices[0], vertices[i - 1], vertices[i]);
  }
  return area;
}

double Physics::Polygon::getArea()
{
  if (count == 0)
    return 0.0;
  // Shoelace formula
  double positive = vertices[0].getY() * vertices[count - 1].getX();
  double negative = vertices[0].getX() * vertices[count - 1].getY();

  for (int i = 1; i < count; i++)
  {
    positive += vertices[i].getY() * vertices[i - 1].getX();
    negative += vertices[i].getX() * vertices[i - 1].getY();
  }

  return abs(positive - negative) / 2;
}