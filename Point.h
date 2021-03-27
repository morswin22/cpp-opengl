#pragma once
#include "Polygon.h"

/** @file Point.h
 *
 * @brief Contains a Point class declaration
 *
 * @author Patryk Janiak
 */

namespace Geometry {

  /**
   * @brief A method to calculate the area of ​​a triangle
   *
   * @param p1 argument of type Point
   * @param p2 argument of type Point
   * @param p3 argument of type Point
   */
  double getTriangleArea(const Point& p1, const Point& p2, const Point& p3);

  /** @brief A point in R^2 space composed of Cartesian coordinates */
  class Point
  {
    /** @brief X-axis Cartesian Coordinate */
    double x;

    /** @brief Y-axis Cartesian Coordinate */
    double y;

  public:

    /** @brief Default constructor */
    Point();

    /**
     * @brief Main constructor
     *
     * @param x argument of double type, passing the value of the x coordinate
     * @param y argument of double type, passing the value of the y coordinate
     */
    Point(double x, double y);

    /**
     * @brief Copy constructor
     *
     * @param p argument of type Point, passing the object to be copied
     */
    Point(const Point& p);

    /** @brief Destructor of the Point class */
    ~Point();

    /**
     * @brief Setter for the value of x
     *
     * @param x argument of double type, passing the value of the x coordinate
     */
    void setX(double x);

    /**
     * @brief Setter for the value of y
     *
     * @param y argument of double type, passing the value of the y coordinate
     */
    void setY(double y);

    /** @brief Getter for value x */
    double getX() const;

    /** @brief Getter for value y */
    double getY() const;

    /** @brief Getter for formatted position of the point (x, y) */
    std::string getString() const;

    /** @brief Method that prints the result of getString() */
    void print() const;

    /** @brief Method calculating the radius */
    double getRadius() const;

    /** @brief Method calculating angle */
    double getAngle() const;

    /**
     * @brief A method to calculate the distance between two points
     *
     * @param p argument of type Point, passing the second point
     */
    double getDistance(const Point& p) const;

    /** @brief Method for computing the length of the vector that creates the point */
    double getLength() const;

    /**
     * @brief A method that adds two vectors together
     *
     * @param p argument of type Point, passing the second point
     * @return Result of adding two Point vectors
     */
    Point add(const Point& p) const;

    /**
     * @brief A method that subtracts two vectors together
     *
     * @param p argument of type Point, passing the second point
     * @return Result of subtracting two Point vectors
     */
    Point subtract(const Point& p) const;

    /**
     * @brief A method that multiplies a vector by a scalar
     *
     * @param scalar argument of type double, passing a scalar value
     * @return The result of multiplying a vector by a scalar
     */
    Point multiply(double skalar) const;

    /** @brief A method that computes the reciprocal of a vector */
    Point getInverse() const;

    /**
     * @brief Method which checks if the given vector is the opposite of the first one
     *
     * @param p argument of type Point, passing the second point
     * @return Result of type bool
     */
    bool isInverse(const Point& p) const;

    /**
     * @brief Method calculating the scoring product of two vectors
     *
     * @param p argument of type Point, passing the second point
     */
    double getProduct(const Point& p) const;

    /**
     * @brief A method that calculates the angle between vectors
     *
     * @param p argument of type Point, passing the second point
     */
    double getAngleBetween(const Point& p) const;

    friend double getTriangleArea(const Point& p1, const Point& p2, const Point& p3);
    friend std::string Polygon::getString() const;
    friend double Polygon::getArea() const;

  };

}