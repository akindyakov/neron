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
#include "include/util/geometry/geometry.h"
#include "include/util/math/math.h"
//=============================================================================

namespace G = Geometry;
namespace M = Math;

G::Interval::Interval(const G::Point2f& pt1,
                      const G::Point2f& pt2)
{
   m_center= pt1;
   G::Reduced_vector dir_vector(pt2.x-pt1.x, pt2.y-pt1.y);
   m_vector = dir_vector;
   /*
   std::cout << "Interval create :"
             << "\n       center: " << pt1.x << " " << pt1.y
             << "\n       vector: " << m_vector.x << " " << m_vector.y << std::endl;
   */
}

G::Interval::Interval(const G::Point2f& pt,
                      const G::Reduced_vector& relative_vec)
            : m_vector(relative_vec)
{
   m_center = pt;
}


void G::Interval::turn(float angle)
{
   m_vector.turn(angle);
}

bool G::Interval::belongingPoint(const G::Point2f& point)const
{
   //float point.x
   return false;
}

bool G::Interval::shapeIntersection(const G::I_Shape& inputShape,
                                    std::list<G::Point2f>* genPoint)
{
   return G::shapeIntersection(*this, inputShape, genPoint);
}

void G::Interval::getX(float y, std::vector<float>* x)const
{
   if ( (y > getFirst().y && y < getSecond().y)
      || (y < getFirst().y && y > getSecond().x) )
   {
      x->push_back(m_center.x + (y-m_center.y)*
                                    m_vector.x/m_vector.y);
   }
}

void G::Interval::getY(float x, std::vector<float>* y)const
{
   if ( (x > getFirst().x && x < getSecond().x)
      || (x < getFirst().x && x > getSecond().x) )
   {
      y->push_back(m_center.y + (x-m_center.x)*m_vector.y/m_vector.x);
   }
}

G::Point2f G::Interval::getFirst()const
{
   return m_center;
}

G::Point2f G::Interval::getSecond()const
{
   return G::Point2f(m_center.x+m_vector.x, m_center.y+m_vector.y);
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

bool G::Interval::belongRectangleArea(const G::Point2f& pt)const
{
   G::Point2f first = getFirst();
   G::Point2f second = getSecond();
   G::Point2f low;
   G::Point2f up;
   M::maxMin(first.x, second.x, &(up.x), &(low.x));
   M::maxMin(first.y, second.y, &(up.y), &(low.y));
   /*
   std::cout << "up_x: "    << up.x
             << "; low.x: " << low.x
             << "; up_y: "  << up.y
             << "; low_y: " << low.y
             << std::endl;
   std::cout << first.x  << " " << first.y  << std::endl;
   std::cout << second.x  << " " << second.y  << std::endl;
   std::cout << pt.x  << " " << pt.y  << std::endl;
   */
   if (  (pt.x < up.x  || M::equal(pt.x, up.x))
      && (pt.y < up.y  || M::equal(pt.y, up.y))
      && (pt.x > low.x || M::equal(pt.x, low.x))
      && (pt.y > low.y || M::equal(pt.y, low.y)) )
   {
      //std::cout << "true\n";
      return true;
   }
   //std::cout << "false\n";
   return false;
}
