/**
 ** autor   Alexander K
 ** date    05.08.2012.22.14
 ** BRIEF   funct for drow I_Shape object
 **         in OpenCV cv::Mat GEOMETRY
*/

#ifndef GEOMETRY_DROW_H
#define GEOMETRY_DROW_H
//=============================================================================
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/geometry.h"
//=============================================================================

namespace Geometry
{
   void drow_shape(const Circle& circ,
                   cv::Mat * outputImage,
                   int line_type,
                   cv::Scalar color);

   void drow_shape(cv::Mat * outputImage, const Interval& circ);
   void drow_shape(cv::Mat * outputImage, const Contour& circ);
   void drow_shape(cv::Mat * outputImage, const Convex_contour& circ);
   void drow_shape(cv::Mat * outputImage, const Line_2d& circ);

} // end of namespace geometry

#endif // GEOMETRY_DROW_H
