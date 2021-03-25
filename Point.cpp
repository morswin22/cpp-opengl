#include "Point.h"
#include <math.h>
#include <iostream>

/** @file Point.cpp
 *
 * @brief Implementation of Point class methods
 *
 * @author Patryk Janiak
 */

using namespace Physics;

Point::Point()
{
  x = 0.0;
  y = 0.0;
}

Point::Point(double _x, double _y)
{
  x = _x;
  y = _y;
}

Point::Point(const Point& _p)
{
  x = _p.x;
  y = _p.y;
}

Point::~Point()
{
}

void Point::print()
{
  std::cout << "(" << x << ", " << y << ")\n";
}

void Point::setX(double _x)
{
  x = _x;
}

double Point::getX()
{
  return x;
}

void Point::setY(double _y)
{
  y = _y;
}

double Point::getY()
{
  return y;
}

double Point::getDistance(Point _p)
{
  double dx = _p.getX() - x;
  double dy = _p.getY() - y;
  return sqrt(dx * dx + dy * dy);
}

double Point::getLength()
{
  return sqrt(x * x + y * y);
}

Point Point::add(Point _p)
{
  Point temp;
  temp.setX(x + _p.getX());
  temp.setY(y + _p.getY());
  return temp;
}

Point Point::subtract(Point _p)
{
  Point temp;
  temp.setX(x - _p.getX());
  temp.setY(y - _p.getY());
  return temp;
}

Point Point::multiply(double skalar)
{
  Point temp;
  temp.setX(skalar * x);
  temp.setY(skalar * y);
  return temp;
}

Point Point::getInverse()
{
  return multiply(-1);
}

bool Point::isInverse(Point _p)
{
  return _p.getX() == -x && _p.getY() == -y;
}

double Point::getProduct(Point _p)
{
  return x * _p.getX() + y * _p.getY();
}

double Point::getAngleBetween(Point _p)
{
  return cos(getProduct(_p) / (getLength() * _p.getLength()));
}