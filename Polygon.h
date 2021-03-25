#pragma once
#include "Point.h"

/** @file Polygon.h
 *
 * @brief Contains a Polygon class declaration
 *
 * @author Patryk Janiak
 */

namespace Geometry {

  /** @brief A polygon consisting of vertices */
  class Polygon
  {
    /** @brief Number of polygon vertices */
    unsigned int count;

    /** @brief An array of Point type vertices */
    Point* vertices;

    /**
     * @brief A private method to calculate the area of ​​a triangle
     *
     * @param p1 argument of type Point
     * @param p2 argument of type Point
     * @param p3 argument of type Point
     */
    double getTriangleArea(const Point& p1, const Point& p2, const Point& p3) const;

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