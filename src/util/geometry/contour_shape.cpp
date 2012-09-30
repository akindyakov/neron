/**
 ** autor   Alexander K
 ** date    08.07.2012.13.33
 ** BRIEF   contour implementation
*/

//=============================================================================
#include <iostream>
#include <iterator>
#include <cmath>
//=============================================================================
#include "include/geometry.h"
#include "include/math.h"
//=============================================================================

namespace G = Geometry;

G::Contour::Contour(const G::Point2f& center, const std::list<G::Reduced_vector>& polinom)
{

}
G::Contour::Contour(const std::list<G::Point2f>& polinom)
{}

void G::Contour::push_back(const G::Reduced_vector& pt)
{

}
void G::Contour::turn(float angle)
{

}
bool G::Contour::belongingPoint(const G::Point2f& point)const
{
   throw G::Geometry_error(
      "functoion Contour::belongingPoint not defined" );
   return false;
}
bool G::Contour::shapeIntersection(const G::I_Shape& inputShape,
                                   std::list<G::Point2f>* genPoint)
{
   return G::shapeIntersection(*this, inputShape, genPoint);
}
float G::Contour::getDistance(const Point2f& pt, Point2f* close_pt)const
{
   return -1;
}
void G::Contour::getX(float y, std::vector<float>* x)const
{}
void G::Contour::getY(float x, std::vector<float>* y)const
{}
