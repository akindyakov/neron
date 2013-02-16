/**
 ** autor   Alexander K
 ** date    08.07.2012.13.33
 ** BRIEF   contour implementation
*/

//==============================================================================
#include <iostream>
#include <iterator>
#include <cmath>
//==============================================================================
#include "include/util/geometry/geometry.h"
#include "include/util/math/math.h"
//==============================================================================

namespace G = Geometry;

G::Contour::Contour(const G::Point2f& center,
                    const std::list<G::Reduced_vector>& polinom)
   : m_vec(polinom)
{
   m_center = center;
   this->toSegments();
}

G::Contour::Contour(const std::list<G::Point2f>& polinom)
{
   std::list<G::Point2f>::const_iterator polIt = polinom.begin();
   m_center = *polIt;
   ++polIt;
   //std::cout << "create convex contour:\n   "
   //          << m_center.x << " " << m_center.y << std::endl;
   for (std::list<G::Point2f>::const_iterator prevPolIt = polinom.begin();
                   polIt != polinom.end(); ++polIt, ++prevPolIt)
   {
      m_vec.push_back(Geometry::Reduced_vector( polIt->x - prevPolIt->x,
                                                polIt->y - prevPolIt->y) );
      //std::cout << "pt: " << polIt->x - prevPolIt->x << " "
      //                    << polIt->y - prevPolIt->y << std::endl;
   }
   this->toSegments();
}

void G::Contour::push_back(float x, float y)
{
   m_vec.push_back(G::Reduced_vector(x,y));
}
void G::Contour::push_back(const G::Reduced_vector& pt)
{
   m_vec.push_back(pt);
}

void G::Contour::turn(float angle)
{
   G::Point2f prevEnd = m_contours.front().m_center;
   for ( std::list< G::Convex_contour >::iterator contIt
                                                   = m_contours.begin();
         contIt != m_contours.end(); ++contIt )
   {
      contIt->turn(angle);
      contIt->m_center = prevEnd;
      prevEnd = contIt->getEnd();
   }
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


// TODO: it needed to remake it with list specific functions !
void G::Contour::toSegments()
{
   std::list<G::Reduced_vector>::const_iterator secondIt = m_vec.begin();
   std::list<G::Reduced_vector>::const_iterator firstIt = secondIt++;
   
   /*
    * If prev pair of vectours and current pair of vectors turn
    * to the equal directions (clockwise or conterclockwise)
    * both prev vector proud and current vector proud will be equal sign.
    * If sign chege we will write current convex_contour to contours list
    * and crete new convex_contour and start to fiil one.
    */
   
   float last_vector_proud = firstIt->vector_proud(*secondIt);
   float now_vector_proud = 0;

   //prepare runing start pt
   G::Point2f runingStartPt(m_center);
   runingStartPt = runingStartPt + *firstIt;

   // prepare first contour
   G::Convex_contour curr_cont(m_center);
   curr_cont.push_back(*firstIt);

   for ( ; secondIt != m_vec.end(); ++firstIt, ++secondIt )
   {
      now_vector_proud = firstIt->vector_proud(*secondIt);
      if ( now_vector_proud * last_vector_proud >= 0)
      {
         curr_cont.push_back(*secondIt);
         last_vector_proud = now_vector_proud;
      }
      else /* sign have been changed */
      {
         m_contours.push_back(curr_cont);
         curr_cont.m_vec.resize(0);
         curr_cont.m_center = runingStartPt;
         curr_cont.push_back(*secondIt);
         last_vector_proud = 0;
      }
      runingStartPt = runingStartPt + *secondIt;
   }
   m_contours.push_back(curr_cont); // write last convex_contour
}

bool G::Contour::isSegmented()
{
   return (m_vec.size() == 0);
}

