/**
 ** autor   Alexander K
 ** date    15.08.2012.20.50
 ** BRIEF   opencv shape show implementation
*/

//=============================================================================
#include <iostream>
#include <iterator>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/geometry.h"
#include "include/geometry_drow.hpp"
//=============================================================================
namespace G = Geometry;

void findBorderPoints( const G::Line_2d& line,
                       cv::Mat* image,
                       std::list<G::Point2f>* borderPt)
{
   std::list<G::Interval> lineborders;

   lineborders.push_back( G::Interval(G::Point2f(0, 0),
                                      G::Point2f(image->cols, 0)) );

   lineborders.push_back( G::Interval(G::Point2f(0,image->rows),
                                     G::Point2f(image->cols,image->rows)) );

   lineborders.push_back( G::Interval(G::Point2f(0,0),
                                      G::Point2f(0,image->rows)) );

   lineborders.push_back( G::Interval(G::Point2f(image->cols,0),
                                      G::Point2f(image->cols,image->rows)) );

   for(std::list<G::Interval>::const_iterator lnIt = lineborders.begin();
         lnIt != lineborders.end(); ++lnIt)
   {
      G::shapeIntersection(line, *lnIt, borderPt);
   }
   //   here we need to delete double point
   // which appear when line crossing angles of images
   G::uniqPoint(borderPt);
   //for (std::list<G::Point2f>::const_iterator it = borderPt.begin();
   //      it != borderPt.end(); ++it)
   //   std::cout << "after uniq : " << it->x << " " << it->y << std::endl;
}

void G::drowCross(cv::Mat* image,
                  const G::Point2f& center, int size,
                  const cv::Scalar& color, int intence)
{

   cv::Point2f leftpt = to_openCV_coord(
                           G::Point2f(center.x - size, center.y),
                           *image );

   cv::Point2f rightpt = to_openCV_coord(
                           Geometry::Point2f(center.x + size, center.y),
                           *image );

   cv::Point2f uppt = to_openCV_coord(
                           G::Point2f(center.x, center.y + size),
                           *image );

   cv::Point2f downpt = to_openCV_coord(
                           G::Point2f(center.x, center.y - size),
                           *image );

   cv::line(*image, leftpt, rightpt, color, intence);
   cv::line(*image, uppt, downpt, color, intence);
}

void G::drowShape(const G::Circle& circ,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color,
                  int second_intence)
{
   cv::Point2f center = to_openCV_coord(circ.m_center, *image);
   cv::circle( *image,center,circ.m_radius,
               first_color, first_intence );

   Geometry::drowCross( image, circ.m_center, circ.m_radius/2,
                        second_color, second_intence);
}

void G::drowShape(const G::Line_2d& line,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color,
                  int second_intence)
{
   std::cout << "drow line \n";
   std::list< G::Point2f > borderPt;
   findBorderPoints(line, image, &borderPt);
   
   if (borderPt.size() != 2)
      throw G::Geometry_error("not correct border - showLine function");
   cv::Point2f pt1  = to_openCV_coord(borderPt.front(), *image);
   cv::Point2f pt2  = to_openCV_coord(borderPt.back(), *image);
   cv::line(*image, pt1, pt2, first_color, first_intence);
   if (second_intence != 0)
   {
      G::drowPoint(line.m_center, image,
                   second_color, second_intence);
      G::drowVector(line.m_center, line.m_direct_vector, image,
                    second_color, second_intence);
   }
}

void G::drowShape(const G::Interval& interval,
                  cv::Mat* image,
                  const cv::Scalar& first_color,
                  int first_intence,
                  const cv::Scalar& second_color,
                  int second_intence)
{
   std::cout << "drow Line_2d\n";

   cv::Point2f pt1 = to_openCV_coord(interval.getFirst(), *image);
   cv::Point2f pt2 = to_openCV_coord(interval.getSecond(), *image);

   cv::line(*image, pt1, pt2, first_color, first_intence);
   if (second_intence != 0)
   {
      cv::circle(*image, pt1,
                  second_intence, second_color, second_intence);
      cv::circle(*image, pt2,
                  second_intence, second_color, second_intence);
   }

}
void Geometry::drowShape(const Geometry::Convex_contour& conv_contour,
                         cv::Mat* image,
                         const cv::Scalar& first_color,
                         int first_intence,
                         const cv::Scalar& second_color,
                         int second_intence)
{
   G::Point2f first_movePt;
   G::Point2f second_movePt = conv_contour.m_center;
   for (std::list<G::Reduced_vector>::const_iterator vecIt = conv_contour.m_vec.begin();
         vecIt != conv_contour.m_vec.end(); ++vecIt)
   {
      first_movePt = second_movePt;
      second_movePt = second_movePt + *vecIt;
      G::drowShape( G::Interval(first_movePt, second_movePt),
                    image,
                    first_color, first_intence );
   }

   if (second_intence != 0)
   {
      G::drowPoint( conv_contour.m_center,
                    image, second_color, second_intence);

      int line_intence = second_intence>1 ? second_intence:second_intence/2;
      G::drowShape( G::Interval(conv_contour.m_center, second_movePt),
                    image, second_color, line_intence );
   }
}
void Geometry::drowShape(const Geometry::Contour& contour,
                         cv::Mat* image,
                         const cv::Scalar& first_color,
                         int first_intence,
                         const cv::Scalar& second_color,
                         int second_intence)
{
   for (std::list<G::Convex_contour>::const_iterator convIt =
                                                contour.m_contours.begin();
         convIt != contour.m_contours.end(); ++convIt)
   {
      G::drowShape(*convIt, image,
                   first_color, first_intence,
                   second_color, second_intence);
   }
}
