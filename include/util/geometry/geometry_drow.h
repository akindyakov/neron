/**
 ** autor   Alexander K
 ** date    05.08.2012.22.14
 ** BRIEF   funct for drow I_Shape object
 **         in OpenCV cv::Mat GEOMETRY
*/

#ifndef GEOMETRY_DROW_H
#define GEOMETRY_DROW_H
//=============================================================================
#include <iostream>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

namespace Geometry
{

   void drowShape(const Circle&,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color = cv::Scalar(0),
                  int second_intence = 0);

   void drowShape(const Line_2d&,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color = cv::Scalar(0),
                  int second_intence = 0);

   void drowShape(const Interval&,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color = cv::Scalar(0),
                  int second_intence = 0);

   void drowShape(const Convex_contour&,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color = cv::Scalar(0),
                  int second_intence = 0);

   void drowShape(const Contour&,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color = cv::Scalar(0),
                  int second_intence = 0);

   void drowCross(cv::Mat* image,
                 const Point2f& center, int size,
                 const cv::Scalar& color, int intence);
   
   void drowVector ( const Reduced_vector& vect,
                     const Point2f& basePt,
                     cv::Mat* image,
                     const cv::Scalar& color,
                     int intence );
   
   void drowGear( cv::Mat* image,
                  const Point2f& center, int size,
                  const cv::Scalar& color, int intence );
   
   void drowPoint(cv::Mat* image,
                  const Point2f& center, int size,
                  const cv::Scalar& color, int intence);
   
   template <class T>
   cv::Point2f to_openCV_coord(const T& vector,
                               const cv::Mat& image)
   {
     // std::cout << " show int : opencv pt2 :" 
     //           << vector.x << " " 
     //           << image.rows-vector.y << std::endl;
      return cv::Point2f(vector.x, image.rows-vector.y);
   }

   template<class T>
   void drowPoint(const Point<T> pt, cv::Mat* image,
                  const cv::Scalar& color, int intence )
   {
      cv::Point2f cvpt = to_openCV_coord(pt, *image);
      cv::circle(*image, cvpt, intence*2, color, intence);
   }

   template<class T>
   void drowVector(const Point<T>& center,
                   const Reduced_vector& vect,
                   cv::Mat* image,
                   const cv::Scalar& color,
                   int intence)
   {
      drowPoint(center, image, color, intence);
      if (intence > 1)
         intence /= 2;
      cv::Point2f pt1 = to_openCV_coord(center, *image);
      cv::Point2f pt2 = to_openCV_coord(center+vect, *image);
      cv::line(*image, pt1, pt2, color, intence);
   }
  } // end of namespace geometry

#endif // GEOMETRY_DROW_H
