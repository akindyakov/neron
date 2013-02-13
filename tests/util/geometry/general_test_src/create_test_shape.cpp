/**
 ** autor   Alexander K
 ** date    11.02.2013.22.34
 ** BRIEF   generating function of simple test figure
*/

//=============================================================================
#include <iostream>
#include <cmath>
//=============================================================================
#include "include/util/geometry/geometry.h"
#include "tests/util/geometry/general_test_src/create_test_shape.h"
//=============================================================================

Geometry::Convex_contour createCircleContour( const Geometry::Point2f& center,
                                              float radius,
                                              int detalisation)
{
   Geometry::Convex_contour ret(center);
   
   ret.push_back(Geometry::Reduced_vector(radius, 0));
   
   Geometry::Reduced_vector discr(6*radius/detalisation,0);
   
   for (int i=0; i<detalisation; ++i)
   {
      Geometry::Reduced_vector pushing(discr);
      pushing.turn(2*M_PI*i/detalisation);
      ret.push_back(pushing);
   }
   
   return ret;
}

Geometry::Convex_contour createAngleContour( const Geometry::Point2f& m_start,
                                             float lenght   )
{
   Geometry::Convex_contour ret(m_start);
   ret.push_back(Geometry::Reduced_vector(lenght, lenght));
   ret.push_back(Geometry::Reduced_vector(-lenght, lenght));
   return ret;
}
