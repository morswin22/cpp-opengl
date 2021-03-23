#include "Point.h"
#include <math.h>
#include <iostream>

/** @file Point.cpp
 *
 * @brief Implementation of Point class methods
 *
 * @author Patryk Janiak
 */

Physics::Point::Point()
{
  x = 0.0;
  y = 0.0;
}

Physics::Point::Point(double _x, double _y)
{
  x = _x;
  y = _y;
}

Physics::Point::Point(const Point& _p)
{
  x = _p.x;
  y = _p.y;
}

Physics::Point::~Point()
{
}

void Physics::Point::print()
{
  std::cout << "(" << x << ", " << y << ")\n";
}

void Physics::Point::setX(double _x)
{
  x = _x;
}

double Physics::Point::getX()
{
  return x;
}

void Physics::Point::setY(double _y)
{
  y = _y;
}

double Physics::Point::getY()
{
  return y;
}

double Physics::Point::getDistance(Point _p)
{
  double dx = _p.getX() - x;
  double dy = _p.getY() - y;
  return sqrt(dx * dx + dy * dy);
}

// double Physics::Point::getRadius()
// {
//   return sqrt(x*x + y*y);
// }

double Physics::Point::getLength()
{
  return sqrt(x * x + y * y);
}

Physics::Point Physics::Point::add(Point _p)
{
  Point temp;
  temp.setX(x + _p.getX());
  temp.setY(y + _p.getY());
  return temp;
}

Physics::Point Physics::Point::subtract(Point _p)
{
  Point temp;
  temp.setX(x - _p.getX());
  temp.setY(y - _p.getY());
  return temp;
}

Physics::Point Physics::Point::multiply(double skalar)
{
  Point temp;
  temp.setX(skalar * x);
  temp.setY(skalar * y);
  return temp;
}

Physics::Point Physics::Point::getInverse()
{
  return multiply(-1);
}

bool Physics::Point::isInverse(Point _p)
{
  return _p.getX() == -x && _p.getY() == -y;
}

double Physics::Point::getProduct(Point _p)
{
  return x * _p.getX() + y * _p.getY();
}

double Physics::Point::getAngleBetween(Point _p)
{
  return cos(getProduct(_p) / (getLength() * _p.getLength()));
}