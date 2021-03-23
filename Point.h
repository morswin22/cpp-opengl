#pragma once

/** @file Point.h
 *
 * @brief Contains a Point class declaration
 *
 * @author Patryk Janiak
 */

namespace Physics {

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
     * @param _x argument of double type, passing the value of the x coordinate
     * @param _y argument of double type, passing the value of the y coordinate
     */
    Point(double _x, double _y);

    /**
     * @brief Copy constructor
     *
     * @param _p argument of type Point, passing the object to be copied
     */
    Point(const Point&);

    /** @brief Destructor of the Point class */
    ~Point();

    /**
     * @brief Setter for the value of x
     *
     * @param _x argument of double type, passing the value of the x coordinate
     */
    void setX(double _x);

    /**
     * @brief Setter for the value of y
     *
     * @param _y argument of double type, passing the value of the y coordinate
     */
    void setY(double _y);

    /** @brief Getter for value x */
    double getX();

    /** @brief Getter for value y */
    double getY();

    /** @brief Method that prints the position of the point (x, y) */
    void print();

    /** @brief Method calculating the radius */
    double getRadius();

    /** @brief Method calculating angle */
    double getAngle();

    /**
     * @brief A method to calculate the distance between two points
     *
     * @param _p argument of type Point, passing the second point
     */
    double getDistance(Point _p);

    /** @brief Method for computing the length of the vector that creates the point */
    double getLength();

    /**
     * @brief A method that adds two vectors together
     *
     * @param _p argument of type Point, passing the second point
     * @return Result of adding two Point vectors
     */
    Point add(Point _p);

    /**
     * @brief A method that subtracts two vectors together
     *
     * @param _p argument of type Point, passing the second point
     * @return Result of subtracting two Point vectors
     */
    Point subtract(Point _p);

    /**
     * @brief A method that multiplies a vector by a scalar
     *
     * @param scalar argument of type double, passing a scalar value
     * @return The result of multiplying a vector by a scalar
     */
    Point multiply(double skalar);

    /** @brief A method that computes the reciprocal of a vector */
    Point getInverse();

    /**
     * @brief Method which checks if the given vector is the opposite of the first one
     *
     * @param _p argument of type Point, passing the second point
     * @return Result of type bool
     */
    bool isInverse(Point _p);

    /**
     * @brief Method calculating the scoring product of two vectors
     *
     * @param _p argument of type Point, passing the second point
     */
    double getProduct(Point _p);

    /**
     * @brief A method that calculates the angle between vectors
     *
     * @param _p argument of type Point, passing the second point
     */
    double getAngleBetween(Point _p);

  };

}