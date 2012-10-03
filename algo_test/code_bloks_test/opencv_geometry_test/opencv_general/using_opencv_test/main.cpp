#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "include/geometry.h"


int main()
{
    Geometry::Point2f pt0(0,0);
    Geometry::Point2f pt1(150,150);
    Geometry::Point2f pt2(0,150);
    Geometry::Point2f pt3(150,0);
    Geometry::Line_2d line1(pt0, pt1);
    //Geometry::Line_2d line2(pt2, pt3);
    Geometry::Circle circ(pt1, 100);
    cv::Mat res(300, 300, CV_8UC1, cv::Scalar(1));

    //drowShape(circ, &res, cv::Scalar(233), 1, cv::Scalar(255), 1);
    drowShape(line1,&res,cv::Scalar(233),1,cv::Scalar(233),1);
    //drowShape(line2,&res,cv::Scalar(233),1,cv::Scalar(233),1);
    cv::namedWindow("show", 0);

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
