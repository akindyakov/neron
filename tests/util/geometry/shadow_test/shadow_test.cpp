/**
 ** autor   Alexander K
 ** date    11.02.2013.22.34
 ** BRIEF   simple test for generating shadow for contour
*/

//=============================================================================
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
#include "include/util/geometry/geometry_drow.h"
#include "include/util/geometry/geometry_transformation.h"
#include "tests/util/geometry/general_test_src/create_test_shape.h"
//=============================================================================

using namespace Geometry;

int main()
{
 
   Geometry::Convex_contour circle = createCircleContour( Geometry::Point2f(500,500),
                                                100, 14);

   std::vector< Geometry::Convex_contour > out_contour;
   std::vector< Geometry::Reduced_vector > start_points;
   start_points.push_back(Geometry::Reduced_vector(1,1));
   start_points.push_back(Geometry::Reduced_vector(-1,1));
   Geometry::createShadow  ( circle, &out_contour, start_points );
}
