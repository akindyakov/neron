/**
 ** autor   Alexander K
 ** date    11.02.2013.22.34
 ** BRIEF   simple test for generating shadow for contour
*/

//=============================================================================
#include <iostream>
#include <vector>
#include <iterator>
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
   Circle
   Interval line(Geometry::Point2f(5,2), Geometry::Point2f(3, 4));
   Line_2d line(Geometry::Point2f(1,2), Geometry::Point2f(3, 4));
   Convex_contour conv_cont(Geometry::Point2f(0, 15), 5, 13); 

   Contour
   return 0;
}
