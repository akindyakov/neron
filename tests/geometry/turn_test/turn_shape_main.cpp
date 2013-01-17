/**
 ** autor   Alexander K
 ** date    06.12.2012.23.18
 ** BRIEF   simple turn test for general geometry shapes
*/

//=============================================================================
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//=============================================================================
#include "include/geometry.h"
#include "include/geometry_drow.h"
//=============================================================================

int main()
{
   cv::Mat res(600, 600, CV_8UC1, cv::Scalar(255));

   // Geometry::Contour cont = createStarContour(res);

   // drowShape(cont,&res,cv::Scalar(233), 1,cv::Scalar(233), 3);
   try
   {
      turningDrowLine(&res);
      cv::namedWindow("show", 0);
   }
   catch(const Geometry::Geometry_error& exept)
   {
      std::cout << exept.name;
   }
    catch(...)
    {
        std::cout << "other error\n";
    }

   while (1)
   {
      cv::imshow("show", res);
      char c = cv::waitKey(100);
      if (c == 27) break; // if was key "Esc" break;
   }
   cv::destroyWindow("show");
   std::cout << "Hello world!" << std::endl;
   return 0;
}
