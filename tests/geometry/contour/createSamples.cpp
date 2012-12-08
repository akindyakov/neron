/**
 **autor   Alexander K
 **date    03.11.2012.15.40
*/

//=============================================================================
#include <list>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/geometry.h"
#include "tests/geometry/contour/drowAndTurn.h"
//=============================================================================

Geometry::Contour createStarContour(const cv::Mat& image)
{
   float len = std::min(image.cols, image.rows);

   Geometry::Point2f center(len/2 , 0);

   std::list< Geometry::Point2f > polinom;
   polinom.push_back(Geometry::Point2f(len/3 , len/3));
   polinom.push_back(Geometry::Point2f(len/2 , 0));
   polinom.push_back(Geometry::Point2f(len/2 + len/6 , len/3));
   polinom.push_back(Geometry::Point2f(len,len/2));
   polinom.push_back(Geometry::Point2f(len/2 + len/6 , len/2 + len/6));
   polinom.push_back(Geometry::Point2f(len/2 , len));
   polinom.push_back(Geometry::Point2f(len/3, len/2 + len/6));
   polinom.push_back(Geometry::Point2f(0 , len/2));
   polinom.push_back(Geometry::Point2f(len/3 , len/3));

   return Geometry::Contour(polinom);
}
