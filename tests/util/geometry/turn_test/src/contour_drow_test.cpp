/**
 **autor   Alexander K
 **date    03.11.2012.15.40
*/

//=============================================================================
#include <list>
#include <opencv2/core/core.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
#include "include/util/geometry/geometry_drow.h"
#include "src/contour_drow_test.h"
//=============================================================================

Geometry::Contour createStarContour(const cv::Mat& image)
{
   float len = std::min(image.cols, image.rows);
   
   Geometry::Point2f center(len/2 , 0);
   
   std::list< Geometry::Point2f > polinom;
   polinom.push_back( Geometry::Point2f( len/4+len*3/16  , len/4+len*3/16 ));
   polinom.push_back( Geometry::Point2f( len/2           , len/4          ));
   polinom.push_back( Geometry::Point2f( len/2 + len/16  , len/4+len*3/16 ));
   polinom.push_back( Geometry::Point2f( 3*len/4         , len/2          ));
   polinom.push_back( Geometry::Point2f( len/2 + len/16  , len/2 + len/16 ));
   polinom.push_back( Geometry::Point2f( len/2           , 3*len/4        ));
   polinom.push_back( Geometry::Point2f( len/4+len*3/16  , len/2 + len/16 ));
   polinom.push_back( Geometry::Point2f( len/4           , len/2          ));
   polinom.push_back( Geometry::Point2f( len/4+len*3/16  , len/4+len*3/16 ));
   
   return Geometry::Contour(polinom);
}


void turningDrowContour(cv::Mat* image)
{
   Geometry::Contour firstCont = createStarContour(*image);
   Geometry::Contour secondCont(firstCont);
   secondCont.turn(0.7f);
   drowShape(firstCont, image, cv::Scalar(0), 2,
                               cv::Scalar(0), 1);
   drowShape(secondCont, image, cv::Scalar(0), 2,
                                cv::Scalar(0), 1);
}
