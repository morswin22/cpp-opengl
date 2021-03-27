#include "Point.h"
#include <math.h>
#include <iostream>
#include <sstream>

/** @file Point.cpp
 *
 * @brief Implementation of Point class methods
 *
 * @author Patryk Janiak
 */

using namespace Geometry;

Point::Point()
{
  this->x = 0.0;
  this->y = 0.0;
}

Point::Point(double x, double y)
{
  this->x = x;
  this->y = y;
}

Point::Point(const Point& p)
{
  this->x = p.x;
  this->y = p.y;
}

Point::~Point()
{
}

std::string Point::getString() const
{
  std::ostringstream sstr;
  sstr << "Point(" << this->x << ", " << this->y << ")";
  return sstr.str();
}

void Point::print() const 
{
  std::cout << this->getString() << "\n";
}

void Point::setX(double x)
{
  this->x = x;
}

double Point::getX() const
{
  return this->x;
}

void Point::setY(double y)
{
  this->y = y;
}

double Point::getY() const
{
  return this->y;
}

double Point::getDistance(const Point& p) const
{
  double dx = p.x - this->x;
  double dy = p.y - this->y;
  return sqrt(dx * dx + dy * dy);
}

double Point::getLength() const
{
  return sqrt(this->x * this->x + this->y * this->y);
}

Point Point::add(const Point& p) const
{
  return Point(this->x + p.x, this->y + p.y);
}

Point Point::subtract(const Point& p) const
{
  return Point(this->x - p.x, this->y - p.y);
}

Point Point::multiply(double skalar) const
{
  return Point(this->x * skalar, this->y * skalar);
}

Point Point::getInverse() const
{
  return this->multiply(-1);
}

bool Point::isInverse(const Point& p) const
{
  return this->x == -p.x && this->y == -p.y;
}

double Point::getProduct(const Point& p) const
{
  return this->x * p.x + this->y * p.y;
}

double Point::getAngleBetween(const Point& p) const
{
  return cos(this->getProduct(p) / (this->getLength() * p.getLength()));
}

double Geometry::getTriangleArea(const Point& p1, const Point& p2, const Point& p3)
{
  return 0.5 * abs((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
}