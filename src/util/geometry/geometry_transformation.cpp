/**
 ** autor   Alexander K
 ** date    01.02.2013.20.00
 ** BRIEF   implementation for create shadow for contour
*/

//=============================================================================
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <cmath>
//=============================================================================
#include "include/util/geometry/geometry_transformation.h"
#include "include/util/geometry/geometry.h"
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
   
   float denominator = src_v.x * finite_v.y - src_v.y * finite_v.x;
   
   float commonPartOfNumerator = finite_v.x*(start_v.y - src_v.y) - finite_v.y*(start_v.x - src_v.x);
   
   float k = - src_v.y * start_v.x + src_v.x * start_v.y;
   if ( denominator == 0 )
      throw(G::Geometry_error("in get paralel finite vector and src vector must not be paralel\n"));
   
   shadow_v->x = src_v.x * commonPartOfNumerator / denominator;
   shadow_v->y = src_v.y * commonPartOfNumerator / denominator;
   
   result_finite_vector->x = finite_v.x * k / denominator;
   result_finite_vector->y = finite_v.y * k / denominator;
//std::cout << " ----------------------------------------------------\n";
//std::cout << " src_v    ( " << src_v.x << "  ;  " << src_v.y << " )\n";
//std::cout << " start_v  ( " << start_v.x << "  ;  " << start_v.y << " )\n";
//std::cout << " finite_v ( " << finite_v.x << "  ;  " << finite_v.y << " )\n";
//std::cout << "         k  = " << k/denominator << "\n";
//std::cout << "\nshadow_v  ( " << shadow_v->x << "  ;  " << shadow_v->y << " )\n";
//std::cout << "finite    ( " << result_finite_vector->x << "  ;  " << result_finite_vector->y << " )\n";
//std::cout << " x: " << start_v.x - result_finite_vector->x + shadow_v->x << "\n";
//std::cout << " y: " << start_v.y - result_finite_vector->y + shadow_v->y << "\n";
}

void G::createShadow  ( const Convex_contour& src_contour, 
                        std::vector< Convex_contour >* out_contour,
                        const std::vector< Reduced_vector >& start_points )
{
   using namespace std;
   using namespace Geometry;
   
   out_contour->resize(0); // correct me if it will be need !
   
   size_t outSize = start_points.size();
   
   // it are neded to create start points for out contours
   for ( vector< Reduced_vector >::const_iterator start_pts_it = start_points.begin();
         start_pts_it != start_points.end();
         ++start_pts_it)
   {
      out_contour->push_back( Convex_contour(src_contour.m_center+*start_pts_it) );
   }
   
   float currLenght = src_contour.m_vec.front().get_lenght();
   float nextLenght = 0;
   
   vector< Reduced_vector > startShadowShift(start_points);
   vector< Reduced_vector > nextShift(start_points.size());
   
   vector< Reduced_vector >* p_firstShift = &startShadowShift;
   vector< Reduced_vector >* p_secondShift = &nextShift;
   
   list< Reduced_vector >::const_iterator nextVectIt = src_contour.m_vec.begin();
   list< Reduced_vector >::const_iterator currVectIt = nextVectIt++;
   
   for ( ; nextVectIt != src_contour.m_vec.end();
         ++currVectIt, ++nextVectIt             )
   {
      nextLenght = nextVectIt->get_lenght();
      
      Reduced_vector bisector = getBisector( -(*currVectIt), *nextVectIt,
                                             currLenght, nextLenght );
      
      for (size_t t=0; t < outSize; ++t) 
      {
         Reduced_vector shadow_vec;
         createParalelVectorShadow( *currVectIt,
                                     p_firstShift->at(t),
                                     bisector,
                                     &shadow_vec,
                                     &p_secondShift->at(t) );
         
         out_contour->at(t).m_vec.push_back(shadow_vec);
      }
      swap( p_secondShift, p_firstShift );
      swap( currLenght, nextLenght );
   }
   Reduced_vector bisector = src_contour.m_vec.back().get_perpendicular();
   for (size_t t=0; t < outSize; ++t) 
   {
      Reduced_vector shadow_vec;
      createParalelVectorShadow( *currVectIt,
                                 p_firstShift->at(t),
                                 bisector,
                                 &shadow_vec,
                                 &p_secondShift->at(t) );
      out_contour->at(t).m_vec.push_back(shadow_vec);
   }

}
void addShadowForSrcVector()
{}
