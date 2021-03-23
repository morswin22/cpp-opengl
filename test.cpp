#define BOOST_TEST_MODULE "Point and Polygon Tests"
#include <boost/test/included/unit_test.hpp>
#include "Polygon.h"

BOOST_AUTO_TEST_CASE(PointCreateEmpty)
{
  Physics::Point p;

  BOOST_CHECK_EQUAL(p.getX(), 0);
  BOOST_CHECK_EQUAL(p.getY(), 0);
}

BOOST_AUTO_TEST_CASE(PolygonCreateEmpty)
{
  Physics::Polygon p;

  BOOST_CHECK_EQUAL(p.getPerimeter(), 0);
  BOOST_CHECK_EQUAL(p.getConvexArea(), 0);
  BOOST_CHECK_EQUAL(p.getArea(), 0);
}

BOOST_AUTO_TEST_CASE(PolygonCheckShoelaceAndConvexArea)
{
  Physics::Polygon p{ new Physics::Point[3]{{0.0, 0.0}, {3.0, 0.0}, {0.0, 4.0}}, 3 };

  BOOST_CHECK_EQUAL(p.getConvexArea(), p.getArea());
}

BOOST_AUTO_TEST_CASE(PolygonCheckPerimeterAndArea)
{
  Physics::Polygon p{ new Physics::Point[3]{{0.0, 0.0}, {3.0, 0.0}, {0.0, 4.0}}, 3 };

  BOOST_CHECK_EQUAL(p.getPerimeter(), 12);
  BOOST_CHECK_EQUAL(p.getArea(), 6);
}
