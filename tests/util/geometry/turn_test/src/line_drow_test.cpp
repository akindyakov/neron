/**
 ** autor   alexander k
 ** email   akindyakov@gmail.com
 ** date    03.11.2012.15.40
*/

//=============================================================================
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
#include "include/util/geometry/geometry_drow.h"

#include "src/line_drow_test.h"
//=============================================================================

void turningDrowLine(cv::Mat * image)
{
   if ( image == NULL )
      return;
   float len = std::min(image->cols, image->rows);
   Geometry::Line_2d b_line(Geometry::Point2f(len/2+100, len/2+len/4),
                           Geometry::Point2f(len/2-100, len/2+len/4));

   Geometry::Point2f turn_center(len/2,len/2);

   int n = 11;

   for (int i =0; i < n; ++i)
   {
      Geometry::Line_2d dr_line(b_line);
      Geometry::turnShape(&dr_line, 2*M_PI*i/n, turn_center);
      Geometry::drowShape(dr_line, image, cv::Scalar(0), 1,
                cv::Scalar(0), 0);
   }
}
