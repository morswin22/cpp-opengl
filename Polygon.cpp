#include "Polygon.h"
#include <iostream>
#include <sstream>
#include <math.h>

/** @file Polygon.cpp
 *
 * @brief Implementation of Polygon class methods
 *
 * @author Patryk Janiak
 */

using namespace Geometry;

Polygon::Polygon()
{
  this->count = 0;
  this->vertices = nullptr;
}

Polygon::Polygon(Point* vertices, unsigned int count)
{
  this->count = count;
  this->vertices = new Point[count];
  for (int i = 0; i < count; i++)
  {
    this->vertices[i] = vertices[i];
  }
}

Polygon::Polygon(const Polygon& p)
{
  this->count = p.count;
  this->vertices = new Point[this->count];
  for (int i = 0; i < this->count; i++)
  {
    this->vertices[i] = p.vertices[i];
  }
}

Polygon::~Polygon()
{
  delete[] this->vertices;
}

void Polygon::setVertices(Point* vertices, int count)
{
  delete[] this->vertices;
  this->count = count;
  this->vertices = new Point[count];
  for (int i = 0; i < count; i++)
  {
    this->vertices[i] = vertices[i];
  }
}

void Polygon::changeVertex(int i, double x, double y)
{
  if (i < 0 || i > this->count)
    throw "Index out of range";
  this->vertices[i].setX(x);
  this->vertices[i].setY(y);
}

void Polygon::setCount(int n)
{
  delete[] this->vertices;
  this->count = n;
  this->vertices = new Point[this->count];
}

std::string Polygon::getString() const
{
  std::ostringstream sstr;
  sstr << "Polygon[\n";
  for (int i = 0; i < this->count; i++)
    sstr << "\tPoint(" << this->vertices[i].x << ", " << this->vertices[i].y << ")\n";
  sstr << "]";
  return sstr.str();
}

void Polygon::print() const
{
  std::cout << this->getString() << "\n";
}

double Polygon::getPerimeter() const
{
  if (this->count == 0)
    return 0.0;
  double perimeter = this->vertices[0].getDistance(this->vertices[this->count - 1]);
  for (int i = 1; i < this->count; i++)
  {
    perimeter += this->vertices[i].getDistance(this->vertices[i - 1]);
  }
  return perimeter;
}

double Polygon::getTriangleArea(const Point& p1, const Point& p2, const Point& p3) const
{
  return 0.5 * abs(((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)));
}

double Polygon::getConvexArea() const
{
  double area{ 0.0 };
  for (int i = 2; i < count; i++)
  {
    area += this->getTriangleArea(this->vertices[0], this->vertices[i - 1], this->vertices[i]);
  }
  return area;
}

double Polygon::getArea() const
{
  if (this->count == 0)
    return 0.0;

  // Shoelace formula
  double positive = this->vertices[0].y * this->vertices[this->count - 1].x;
  double negative = this->vertices[0].x * this->vertices[this->count - 1].y;

  for (int i = 1; i < this->count; i++)
  {
    positive += this->vertices[i].y * vertices[i - 1].x;
    negative += this->vertices[i].x * vertices[i - 1].y;
  }

  return abs(positive - negative) * 0.5;
}