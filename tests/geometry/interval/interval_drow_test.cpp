/**
 ** autor   alexander k
 ** email   akindyakov@gmail.com
 ** date    11.11.2012.00.59
*/

//=============================================================================
#include <math>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/geometry.h"
#include "include/geometry_drow.h"
#include "tests/geometry/contour/line_drow_test.h"
//=============================================================================

void intervalTurningDrow(cv::Mat* image)
{
   if ( image == NULL )
      return;
   float len = std::min(image->cols, image->rows);
   int n = 100;
   
   Geometry::Interval interval(Geometry::Point2f(len/2-len/4, len/2 + len/4),
                              Geometry::Point2f(len/2+len/4, len/2 + len/4));

   for (int i = 0; i < n; ++i)
   {
      Geometry::Interval second(line);
      turnShape(&second, (M_PI*2/n)*i );
      drowShape(second, image, cv::Scalar(233), 1,cv::Scalar(233), 2);
   }
}
