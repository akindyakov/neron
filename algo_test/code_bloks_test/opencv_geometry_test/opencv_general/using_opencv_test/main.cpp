#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "include/geometry.h"
#include "include/geometry_drow.hpp"

int main()
{
    Geometry::Point2f pt0(0,0);
    Geometry::Point2f pt1(150,150);
    Geometry::Point2f pt2(0,150);
    Geometry::Point2f pt3(150,0);
    Geometry::Point2f pt4(100,0);
    Geometry::Point2f pt5(0,100);
    Geometry::Point2f outpt(-10,-100);
    Geometry::Line_2d line1(pt0, pt1);
    Geometry::Line_2d line2(pt2, pt3);
    Geometry::Circle circ(pt1, 100);
    Geometry::Interval interval1(pt4, pt5);
    Geometry::Interval interval2(outpt, pt5);
    cv::Mat res(300, 300, CV_8UC1, cv::Scalar(1));

    //drowShape(circ, &res, cv::Scalar(233),1, cv::Scalar(255),1);
    std::cout << "drow line 1\n";
    //drowShape(line1,&res,cv::Scalar(233), 1,cv::Scalar(233), 1);
    std::cout << "drow line 2\n";
    //drowShape(line2,&res,cv::Scalar(233), 1,cv::Scalar(233), 1);
    std::cout << "drow interval1\n";
    drowShape(interval1, &res, cv::Scalar(233), 1, cv::Scalar(233), 1);
    std::cout << "drow interval2\n";
    drowShape(interval2,&res,cv::Scalar(233), 1,cv::Scalar(233), 1);
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
