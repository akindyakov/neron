/**
 ** autor   Alexander K
 ** date    01.02.2013.20.00
 ** BRIEF   implementation for create shadow for contour
*/

//=============================================================================
#include <iostream>
#include <iterator>
#include <cmath>
//=============================================================================
#include "include/util/geometry/geometry_transformation.h"
#include "include/util/math/math.h"
//=============================================================================

namespace G = Geometry;

void G::createShadow  ( const Convex_contour& src_contour, 
                        std::vector< Convex_contour >* out_contour,
                        const std::vector< Reduced_vector >& start_points )
{
   using namespace std;
   using namespace Geometry;
   
   out_contour->resize(0); // correct me if it will be need !
   
   /*      {  start.x + shadow.x + k*B = src.x
    *     {   start.y + shadow.y - k*A = src.y
    *      {  shadow.x * src.y = shadow.y * src.x
    *
    *                                                                   2
    *                src.x (start.y - src.y) B + src.x start.x A - src.x  A
    *   shadow.x = - ---------------------------------------------------------
    *                       src.y B + src.x A
    *
    *                                      2
    *                (src.y start.y - src.y ) B + src.y start.x A - src.x src.y A
    *   shadow.y = - -------------------------------------------------------------
    *                       src.y B - src.x A
    *
    *          src.y start.x - src.x start.y
    *   k = - ------------------------------
    *                 src.y B + src.x A
    */
    
   //vector< float > distance;
   
   float prev_vect_proud;
   float curr_vect_proud;
   
   vector< Reduced_vector > prevShadowShifts(start_points);
   vector< Reduced_vector > nextBisector(start_points.size());
   
   // it are neded to create start points for out contours
   for ( vector< Reduced_vector >::const_iterator start_pts_it = start_points.begin();
         start_pts_it != start_points.end();
         ++start_pts_it)
   {
      out_contour->push_back( src_contour.m_center + start_pts_it );
   }
   
   for ( vector< Reduced_vector >::const_iterator 
         src_it = src_cont.m_vec.begin(), src_it = src_cont.m_vec.begin();
         src_it != src_cont.m_vec.end();
         ++src_it )
   {
      for ( vector< Convex_contour >::iterator out_cont_it = start_points.begin();
            start_pts_it != start_points.end();
            ++start_pts_it)
      {
         Reduced_vecotor bisector = createBisector(
      }
   }
}
