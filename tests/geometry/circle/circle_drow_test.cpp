/**
 **autor   Alexander K
 **date    06.11.2012.23.18
*/

//=============================================================================
#include <list>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/geometry.h"
#include "include/geometry_drow.h"

#include "tests/geometry/contour/drowAndTurn.h"
//=============================================================================

void turningDrow(cv::Mat* image)
{
   if ( image == NULL )
      return;
   float len = std::min(image->cols, image->rows);
   Geometry::Circle bcirc(Geometry::Point2f(len/2+len/4, len/2), len/4);

   Geometry::Point2f turn_center(len/2,len/2);
   int n = 5;

   for (int i =0; i < n; ++i)
   {
      Geometry::Circle dr_circ(bcirc);
      Geometry::turnShape(&dr_circ, M_PI*i/n, turn_center);
      Geometry::drowShape(dr_circ, image, cv::Scalar(0), 1,
                cv::Scalar(0), 2);
   }
}
