/**
 ** autor   Alexander K
 ** date    08.07.2012.13.33
 ** BRIEF   other func implementation
*/

//=============================================================================
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <cfloat>
#include <cstdlib>
#include <ctime>
//=============================================================================
#include "include/geometry.h"
#include "include/math.h"
//=============================================================================

namespace G = Geometry;

float Geometry::distance(const Geometry::Point2f& pt1,
                         const Geometry::Point2f& pt2)
{
   return std::sqrt((pt1.x-pt2.x)*(pt1.x-pt2.x)+(pt1.y-pt2.y)*(pt1.y-pt2.y));
}

void Geometry::getBorder(const std::list<Geometry::Point2f>& points,
                         Geometry::Point2f* minPt, Geometry::Point2f* maxPt)
{
   *minPt = Geometry::Point2f(FLT_MAX , FLT_MAX );
   *maxPt = Geometry::Point2f(-FLT_MAX , -FLT_MAX );
   for ( std::list<Geometry::Point2f>::const_iterator ptIt = points.begin();
         ptIt != points.end(); ++ptIt )
   {
      if ( minPt->x > ptIt->x )
         minPt->x = ptIt->x;
      if ( maxPt->x < ptIt->x )
         maxPt->x = ptIt->x;
      if ( minPt->y > ptIt->y )
         minPt->y = ptIt->y;
      if ( maxPt->y < ptIt->y )
         maxPt->y = ptIt->y;
   }
}

void Geometry::getVerticalBorderPoint(const std::list<Geometry::Point2f>&points,
                                      Geometry::Point2f* pt_min, Geometry::Point2f* pt_max)
{
   pt_min->x = FLT_MAX;
   pt_max->x = -FLT_MAX;
   for ( std::list<Geometry::Point2f>::const_iterator ptIt = points.begin();
         ptIt != points.end(); ++ptIt )
   {
      if ( pt_min->x > ptIt->x )
         *pt_min = *ptIt;
      if ( pt_max->x < ptIt->x )
         *pt_max = *ptIt;
   }
}

void Geometry::getHorizontalBorderPoint(const std::list<Geometry::Point2f>& points,
                          Geometry::Point2f* pt_min, Geometry::Point2f* pt_max)
{
   pt_min->y = FLT_MAX ;
   pt_max->y = -FLT_MAX ;
   for ( std::list<Geometry::Point2f>::const_iterator ptIt = points.begin();
         ptIt != points.end(); ++ptIt )
   {
      if ( pt_min->y > ptIt->y )
         *pt_min = *ptIt;
      if ( pt_max->y < ptIt->y )
         *pt_max = *ptIt;
   }
}

void Geometry::contourToConvexContour(Geometry::Contour* cont)
{}

std::list<Geometry::Point2f> pointToConvex(const std::list<Geometry::Point2f>& points,
                                const float sizeStep)
{
   Geometry::Point2f pt_min, pt_max;
   Geometry::getVerticalBorderPoint(points, &pt_min, &pt_max);

   float f_n_step = (pt_max.x - pt_min.x)/sizeStep;
   int n_step = static_cast<int>(f_n_step);
   if ( f_n_step-n_step > 0 )
      ++n_step;
   std::vector< std::list<Geometry::Point2f> > boxes(n_step);

   // sort to boxes
   for ( std::list<Geometry::Point2f>::const_iterator ptIt = points.begin();
         ptIt != points.end(); ++ptIt )
   {
      int step = static_cast<int>(ptIt->x/sizeStep);
      std::cout << "pt.x : " << ptIt->x << "   step : " << step << std::endl;
      boxes[step].push_back(*ptIt);
   }

   std::list<Geometry::Point2f> maxBoxPoints;
   std::list<Geometry::Point2f> minBoxPoints;
   for ( std::vector< std::list<Geometry::Point2f> >::iterator
                                          boxIt = boxes.begin();
         boxIt != boxes.end(); ++boxIt )
   {
      Geometry::Point2f box_pt_min, box_pt_max;
      Geometry::getHorizontalBorderPoint(*boxIt, &box_pt_min, &box_pt_max);

      minBoxPoints.push_back(box_pt_min);
      maxBoxPoints.push_back(box_pt_max);
   }
   std::list<Geometry::Point2f> polinom;
   polinom.push_back(pt_min);
   polinom.insert(polinom.end(), minBoxPoints.begin(), minBoxPoints.end());
   polinom.push_back(pt_max);
   polinom.insert(polinom.end(), maxBoxPoints.begin(), maxBoxPoints.end());
   return polinom;
}

template <class T>
Geometry::Point<T>::Point(T _x, T _y)
    : x(_x),
      y(_y)
{}

template <class T>
Geometry::Point<T>::Point()
   : x(0), y(0)
{}

//template <class T>
//Geometry::Point<T>::Point(T _x, T _y)
//   : x(_x), y(_y)
//{}

template <class T>
Geometry::Point<T>::Point(const Point<T>& pt)
   : x(pt.x), y(pt.y)
{}

template <class T>
Geometry::Point<T> Geometry::operator + (Point<T>& vec1, Point<T>& vec2)
{
   return Geometry::Point<T> (vec1.x+vec2.x, vec1.y+vec2.y);
}

/*
Geometry::Point2f::Point2f(const float _x, const float _y)
                    : x(_x),
                      y(_y)
{}

Geometry::Point2f::Point2f()
                    : x(0),
                      y(0)
{}

Geometry::Point2f::Point2f(const Geometry::Point2f& pt)
                    : x(pt.x),
                      y(pt.y)
{}
*/
Geometry::Reduced_vector::Reduced_vector()
{
    x = y = 0;
}

Geometry::Reduced_vector::Reduced_vector(float _x, float _y)
{
    x = _x; y = _y;
}

Geometry::Reduced_vector::Reduced_vector(const Geometry::Point2f& start_pt,
                                         const Geometry::Point2f& end_pt)
{
    x = end_pt.x-start_pt.x;
    y = end_pt.y-start_pt.y;
}

void Geometry::Reduced_vector::turn(float angle)
{
   float sinPhi = std::sin(angle);
   float cosPhi = std::cos(angle);
   float new_x, new_y;
   new_x = x*cosPhi - y*sinPhi;
   new_y = x*sinPhi + y*cosPhi;
   x = new_x;
   y = new_y;
}

Geometry::Reduced_vector Geometry::Reduced_vector::get_perpendicular()const
{
   return Geometry::Reduced_vector(1, -x/y);
}

void G::Reduced_vector::set_lenght(float len)
{
   float old_len = this->get_lenght();
   *(this)*(len/old_len);
}

float G::Reduced_vector::get_lenght()
{
   return G::distance(G::Point2f(x,y),G::Point2f(0,0));
}

float Geometry::Reduced_vector::vector_proud(const Reduced_vector& vec)const
{
   return this->x*vec.y - this->y*vec.x;
}

float Geometry::operator * (const Geometry::Reduced_vector& vec1,
                  const Geometry::Reduced_vector& vec2)
{
   return vec1.x*vec2.x + vec1.y*vec2.y;
}

Geometry::Reduced_vector Geometry::operator * (const Geometry::Reduced_vector& vec, float c)
{
   return Geometry::Reduced_vector(vec.x*c, vec.y*c);
}

Geometry::Reduced_vector Geometry::operator * (float c, const Geometry::Reduced_vector& vec)
{
   return Geometry::Reduced_vector(vec.x*c, vec.y*c);
}

Geometry::Reduced_vector Geometry::operator + (const Geometry::Reduced_vector& vec1,
                                               const Geometry::Reduced_vector& vec2)
{
   return Geometry::Reduced_vector(vec1.x+vec2.x, vec1.y+vec2.y);
}

Geometry::Point2f Geometry::operator + (const Geometry::Point2f& pt,
                                        const Geometry::Reduced_vector& vec)
{
   return Geometry::Point2f(pt.x+vec.x, pt.y+vec.y);
}

Geometry::Reduced_vector Geometry::Reduced_vector::operator - ()
{
   return Geometry::Reduced_vector(-this->x,-this->y);
}

//  --- auxiliary functions ---
std::list<Geometry::Point2f> Geometry::getRandomPointCloud(int n,
                                                           Point2f lowBorder,
                                                           Point2f upBorder)
{
   if ((lowBorder.x > upBorder.x)
       || (lowBorder.y > lowBorder.y))
      throw Geometry::Geometry_error("up must be larger then low");

   std::srand(std::time(NULL));
   int interval_for_x =static_cast<int>(upBorder.x - lowBorder.x);
   int interval_for_y =static_cast<int>(upBorder.y - lowBorder.y);
   std::list<Geometry::Point2f> ret_rand_list;
   for (int i=0; i<n; ++i)
   {
      float x = rand()%interval_for_x;
      float y = rand()%interval_for_y;
      ret_rand_list.push_back(Geometry::Point2f(x,y));
   }
   return ret_rand_list;
}

template <class T>
void G::minMaxPointCloud( const std::list< G::Point<T> >& cloud,
                          G::Point<T>* outMaxPoint,
                          G::Point<T>* outMinPoint )
{
   if ( outMaxPoint != NULL && outMinPoint != NULL )
   {
      typename std::list< G::Point<T> >::const_iterarator p_clfirst = cloud.begn();
      typename std::list< G::Point<T> >::const_iterarator p_clsecond = cloud.begin();
      if ( cloud.size()%2 == 0)
      {
         ++p_clsecond;
         Math::maxMin( p_clfirst->x, p_clfirst->x,
                 &(outMaxPoint->x), &(outMinPoint->x));
         Math::maxMin( p_clfirst->y, p_clfirst->y,
                 &(outMaxPoint->y), &(outMinPoint->y));
         p_clsecond += 2;
         p_clfirst += 2;
      }
      else
      {
         *outMaxPoint = *p_clfirst;
         *outMinPoint = *p_clfirst;
         p_clsecond += 2;
         p_clfirst += 1;
      }
      for ( ; p_clsecond != cloud.end(); p_clsecond += 2, p_clfirst += 2 )
      {
         Math::pairElementSort(p_clfirst->x, p_clsecond->x,
                         &(outMaxPoint->x), &(outMinPoint->x));
         Math::pairElementSort(p_clfirst->y, p_clsecond->y,
                         &(outMaxPoint->y), &(outMinPoint->y));
      }
   }
   return;
}

template <class T>
G::Point2f G::searchCenterCloud(const std::list< G::Point<T> >& cloud)
{
   return G::Point2f(0,0);
}

template <class T>
void G::uniqPoint( std::list< G::Point<T> >* cloud )
{
   typename std::list< G::Point<T> >::iterator endit = cloud->end() - 1;
   for ( typename std::list< Point<T> >::iterator it1 = cloud->begin();
         it1 != endit; ++it1)
      for ( typename std::list< Point<T> >::iterator it2 = it1+1;
            it2 != endit; ++it2)
      {
         if ( Math::equal(it1->x, it2->x) && Math::equal(it1->x, it2->x) )
         {
            std::swap(endit, it2);
            --endit;
            --it2;
         }
      }
   cloud->erase(endit, cloud->end());
}
