/**
 ** autor   Alexander K
 ** date    08.07.2012.13.33
 ** BRIEF   2d line implementation
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

G::Line_2d::Line_2d(const G::Point2f& pt1,
                    const G::Point2f& pt2)
{
   m_center= pt1;
   Geometry::Reduced_vector dir_vector(pt1.x - pt2.x, pt1.y - pt2.y);
   m_direct_vector = dir_vector;
   //std::cout << "center" << m_center.x   << " " << m_center.y << std::endl
   //          << "vector" << dir_vector.x << " " << dir_vector.y << std::endl;
}
G::Line_2d::Line_2d(const G::Interval& inl)
            : m_direct_vector(inl.m_vector)
{
   m_center = inl.m_center;
}
Geometry::Line_2d::Line_2d(const G::Reduced_vector& direct_vector,
                           const G::Point2f& pt)
            : m_direct_vector(direct_vector)
{
   m_center = pt;
}

void Geometry::Line_2d::turn(float angle)
{
   m_direct_vector.turn(angle);
}

bool Geometry::Line_2d::belongingPoint(const Geometry::Point2f& point)const
{
   //float point.x
   return false;
}

bool G::Line_2d::shapeIntersection(const G::I_Shape& inputShape,
                                   std::list<G::Point2f>* genPoint)
{
   return G::shapeIntersection(*this, inputShape, genPoint);
}

float Geometry::Line_2d::getDistance(const Point2f& pt, Point2f* close_pt)const
{
   Geometry::Line_2d perp_line( pt, m_direct_vector.get_perpendicular() );
   std::list<Geometry::Point2f> inter_points;
   Geometry::shapeIntersection(*this, perp_line, &inter_points);

   if ( close_pt != NULL )
      *close_pt = inter_points.front();

   return Geometry::distance(inter_points.front(), pt);
}
void Geometry::Line_2d::getX(float y, std::vector<float>* x)const
{
   x->push_back(m_center.x + (y-m_center.y)*
                              m_direct_vector.x/m_direct_vector.y);
}
void Geometry::Line_2d::getY(float x, std::vector<float>* y)const
{
   y->push_back(m_center.y + (x-m_center.x)*
                              m_direct_vector.y/m_direct_vector.x);
}
