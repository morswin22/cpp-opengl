#pragma once
#include<string>

/** @file Polygon.h
 *
 * @brief Contains a Polygon class declaration
 *
 * @author Patryk Janiak
 */

namespace Geometry {

  // Forward declaration of Point
  class Point;

  /** @brief A polygon consisting of vertices */
  class Polygon
  {
    /** @brief Number of polygon vertices */
    unsigned int count;

    /** @brief An array of Point type vertices */
    Point* vertices;

  public:

    /** @brief Default constructor */
    Polygon();

    /**
     * @brief Main constructor
     *
     * @param _vertices argument of type Point*, passing the vertex array of the polygon
     * @param _count argument of type unsigned int, passing the number of vertices
     */
    Polygon(Point* _vertices, unsigned int _count);

    /**
     * @brief Copy constructor
     *
     * @param _p argument of type Polygon, passing the object to be copied
     */
    Polygon(const Polygon& _p);

    /** @brief Polygon class destructor */
    ~Polygon();

    /**
     * @brief A method for constructing an array of vertices.
     *
     * @param _vertices argument of type Point* that passes an array of the polygon's vertices
     * @param _count argument of type unsigned int, passing the number of vertices.
     */
    void setVertices(Point* _vertices, int _count);

    /**
     * @brief A method to change the coordinates of the i-th vertex.
     *
     * @param i an argument of type int which passes the number of the vertex to change
     * @param x argument of type double that passes a new value to the x-coordinate
     * @param y argument of type double that passes a new value to the y-coordinate
     */
    void changeVertex(int i, double x, double y);

    /**
     * @brief A method to set the number of vertices.
     *
     * @param n argument of type int which passes the number of vertices
    */
    void setCount(int n);

    /** @brief Getter for formatted position of the vertices */
    std::string getString() const;

    /** @brief Method that prints the result of getString() */
    void print() const;

    /** @brief Method for calculating the perimeter of a polygon */
    double getPerimeter() const;

    /** @brief Method calculating the area of ​​a convex polygon */
    double getConvexArea() const;

    /** @brief Method calculating the area of ​​any polygon */
    double getArea() const;
  };

}

#include "Point.h"