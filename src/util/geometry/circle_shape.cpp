/**
 ** autor   Alexander K
 ** email   akindyakov@gmail.com
 ** date    08.07.2012.13.33
 ** BRIEF   circle implementation
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

G::Circle::Circle(const G::Point2f& center, float radius)
   : m_radius(radius)
{
     m_center = center;
     //m_center(Geometry::Point2f(0,0));
}

G::Circle::Circle(const G::Point2f& center,
                  const G::Point2f& circlePoint)
{
   m_center = center;
   m_radius = G::distance(center, circlePoint);
}
G::Circle::Circle(const G::Point2f& pt1,
                  const G::Point2f& pt2,
                  const G::Point2f& pt3)
{
   std::cout << "realisation not compleet!\n";
}

void G::Circle::create(const G::Point2f& center,
                              float radius)
{
   m_center = center;
   m_radius = radius;
}

void G::Circle::create(const G::Point2f& center,
                              const G::Point2f& circlePoint)
{
   m_radius = distance(center, circlePoint);
   m_center = center;
}

void G::Circle::create(const G::Point2f& pt1,
                              const G::Point2f& pt2,
                              const G::Point2f& pt3)
{
   std::cout << "Circle::create(Point2f pt1, Point2f pt2, Point2f pt3)\n"
             << "   realisation not compleet!\n";
}

void G::Circle::turn(float angle)
{
}

bool G::Circle::belongingPoint(const G::Point2f& point)const
{
   float realRad =
         (m_center.x-point.x)*(m_center.x-point.x)
            +(m_center.y-point.y)*(m_center.y-point.y);
   return Math::equal(realRad, m_radius);
}

bool G::Circle::insidePoint(const G::Point2f& point)const
{
   return m_radius < Geometry::distance(m_center, point);
}

bool G::Circle::shapeIntersection(const I_Shape& inputShape,
                                  std::list<G::Point2f>* genPoint)
{
   return G::shapeIntersection(*this, inputShape, genPoint);
}

float G::Circle::getDistance(const G::Point2f& pt, Point2f* close_pt)const
{
   float dst_to_center = G::distance(pt, m_center);
   if ( close_pt != NULL )
   {
      G::Reduced_vector centerToPt(m_center, pt);
      centerToPt.set_lenght(m_radius);
      *close_pt = m_center + centerToPt;
   }
   return dst_to_center - m_radius;
}
void G::Circle::getX(float y, std::vector<float>* x)const
{
   float leg = std::sqrt( m_radius*m_radius - (m_center.y-y)*(m_center.y-y) );
   x->push_back(m_center.x + leg);
   x->push_back(m_center.x - leg);
}

void G::Circle::getY(float x, std::vector<float>* y)const
{
   float leg = std::sqrt( m_radius*m_radius - (m_center.x-x)*(m_center.x-x) );
   y->push_back(m_center.y + leg);
   y->push_back(m_center.y - leg);
}
