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

void createParalelVectorShadow( const G::Reduced_vector& src_v,
                                const G::Reduced_vector& start_v,
                                const G::Reduced_vector& finite_v,
                                G::Reduced_vector* shadow_v,
                                G::Reduced_vector* result_finite_vector )
{
   /*      {  start.x + shadow.x - k*B = src.x
    *     {   start.y + shadow.y - k*A = src.y
    *      {  shadow.x * src.y = shadow.y * src.x
    *
    *                                                                     2
    *                  src_x (start_y - src_y) B - src_x start_x A + src_x  A
    *    shadow_x = - ------------------------------------------------------ 
    *                                  src_y B - src_x A
    *
    *                                       2
    *                 (src_y start_y - src_y ) B - src_y start_x A + src_x src_y A
    *    shadow_y = - ------------------------------------------------------------
    *                                  src_y B - src_x A
    * 
    *               src_y start_x - src_x start_y
    *           k = -----------------------------
    *                   src_y B - src_x A
    *
    */
   
   float denominator = src_v.y * finite_v.x - src_v.x * finite_v.y;
   float commonPartOfNumerator = (start_v.y - src_v.y)*finite_v.x - finite_v.y*(start_v.x + src_v.x);
   float k = src_v.y * start_v.x - src_v.x * start_v.y;
   if ( denominator == 0 )
      throw(G::Geometry_error("in get paralel finite vector and src vector must not be paralel"));
   
   shadow_v->x = src_v.x * commonPartOfNumerator / denominator;
   shadow_v->x = src_v.x * commonPartOfNumerator / denominator;
   
   result_finite_vector->x = finite_v.x * k / denominator;
   result_finite_vector->y = finite_v.y * k / denominator;
}

void G::createShadow  ( const Convex_contour& src_contour, 
                        std::vector< Convex_contour >* out_contour,
                        const std::vector< Reduced_vector >& start_points )
{
   using namespace std;
   using namespace Geometry;
   
   out_contour->resize(0); // correct me if it will be need !
      
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
      out_contour->push_back( src_contour.m_center + *start_pts_it );
   }
   
   //for ( vector< Reduced_vector >::const_iterator src_it = src_contour.m_vec.begin();
   //      src_it != src_contour.m_vec.end();
   //      ++src_it )
   //{
   //   for ( vector< Convex_contour >::iterator out_cont_it = start_points.begin();
   //         start_pts_it != start_points.end();
   //         ++start_pts_it)
   //   {
   //      //Reduced_vecotor bisector = createBisector();
   //   }
   //}
}
