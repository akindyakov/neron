/**
 **autor   Alexander K
 **date    06.11.2012.23.18
*/

//=============================================================================
#include <list>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/geometry.h"
#include "tests/geometry/contour/drowAndTurn.h"
//=============================================================================

void turningDrow(cv::Mat* image)
{
   if ( image == NULL )
      return;
   float len = std::min(image->cols, image->rows);
   Geometry::Circle(Geometry::Point2f(len/2+len/4
}
