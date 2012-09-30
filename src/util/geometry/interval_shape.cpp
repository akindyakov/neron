/**
 ** autor   Alexander K
 ** email   akindyakov@gmail.com
 ** date    08.07.2012.13.33
 ** BRIEF   interval implementation
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

Geometry::Interval::Interval(const Geometry::Point2f& pt1,
                             const Geometry::Point2f& pt2)
{
   m_center= pt1;
   Geometry::Reduced_vector dir_vector(pt2.x-pt1.x, pt2.y-pt1.y);
   m_vector = dir_vector;
}

Geometry::Interval::Interval(const Point2f& pt,
                             const Reduced_vector& relative_vec)
            : m_vector(relative_vec)
{
   m_center = pt;
}


void G::Interval::turn(float angle)
{
   m_vector.turn(angle);
}

bool Geometry::Interval::belongingPoint(const Geometry::Point2f& point)const
{
   //float point.x
   return false;
}

bool Geometry::Interval::shapeIntersection(const Geometry::I_Shape& inputShape,
                                        std::list<Geometry::Point2f>* genPoint)
{
   return G::shapeIntersection(*this, inputShape, genPoint);
}

void Geometry::Interval::getX(float y, std::vector<float>* x)const
{
   if ( (y > getFirst().y && y < getSecond().y)
      || (y < getFirst().y && y > getSecond().x) )
   {
      x->push_back(m_center.x + (y-m_center.y)*
                                    m_vector.x/m_vector.y);
   }
}

void Geometry::Interval::getY(float x, std::vector<float>* y)const
{
   if ( (x > getFirst().x && x < getSecond().x)
      || (x < getFirst().x && x > getSecond().x) )
   {
      y->push_back(m_center.y + (x-m_center.x)*m_vector.y/m_vector.x);
   }
}

Geometry::Point2f Geometry::Interval::getFirst()const
{
   return m_center;
}

Geometry::Point2f Geometry::Interval::getSecond()const
{
   return Geometry::Point2f(m_center.x+m_vector.x, m_center.y+m_vector.y);
}

float G::Interval::getDistance(const G::Point2f& pt, G::Point2f* close_pt)const
{
   G::Line_2d interline(*this);
   G::Point2f line_close_pt;
   float lineDist = interline.getDistance(pt, &line_close_pt);
   if ( !belongRectangleArea(line_close_pt) )
   {
      G::Point2f first = getFirst();
      G::Point2f second = getSecond();
      float first_dist = G::distance(pt, first);
      float second_dist = G::distance(pt, second);
      if (first_dist < second_dist)
      {
         lineDist = first_dist;
         *close_pt = first;
      }
      else
      {
         lineDist = second_dist;
         *close_pt = second;
      }
   }
   else
   {
      *close_pt = line_close_pt;
   }
   return lineDist;
}

bool G::Interval::belongRectangleArea(const Point2f& pt)const
{
   G::Point2f first = getFirst();
   G::Point2f second = getSecond();

   if (  pt.x < std::min(first.x, second.x)
      && pt.y < std::min(first.y, second.y)
      && pt.x > std::max(first.x, second.x)
      && pt.y > std::max(first.y, second.y) )
   {
      return true;
   }
   return false;
}
