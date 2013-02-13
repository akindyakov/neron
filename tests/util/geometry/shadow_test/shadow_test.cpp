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
   int side = 1200;
   cv::Mat image(side, side, CV_8UC1, cv::Scalar(255));
   //Geometry::Convex_contour circle = createCircleContour( Geometry::Point2f(500,500),
   //                                             100, 14);
   Geometry::Convex_contour circle = createAngleContour( Geometry::Point2f(200,200), 400);

   Geometry::drowShape(circle, &image, cv::Scalar(0), 1,cv::Scalar(0), 0);
   
   std::vector< Geometry::Convex_contour > out_contour;
   std::vector< Geometry::Reduced_vector > start_points;
   
   start_points.push_back(Geometry::Reduced_vector(100,-70));
   start_points.push_back(Geometry::Reduced_vector(-70,100));
  
   for(std::vector< Geometry::Reduced_vector >::iterator it = start_points.begin();
         it != start_points.end(); ++it)
   {
      drowVector ( *it, Geometry::Point2f(200,200), &image, cv::Scalar(50), 1 );
   }
   
   try
   {
      Geometry::createShadow  ( circle, &out_contour, start_points );
      
      for (int i=0; i < out_contour.size(); ++i)
      {
         Geometry::drowShape(out_contour.at(i), &image, cv::Scalar(0), 1, cv::Scalar(0), 0);
      }
   }
   catch (const Geometry::Geometry_error& exept)
   {
      std::cout << "Geometry error :" << exept.name <<std::endl;
   }
   catch(...)
   {
        std::cout << "other error\n";
   }
   
   cv::namedWindow("show", 0);
   while (1)
   {
      cv::imshow("show", image);
      char c = cv::waitKey(100);
      if (c == 27) break; // if was key "Esc" break;
   }
   cv::destroyWindow("show");
}
