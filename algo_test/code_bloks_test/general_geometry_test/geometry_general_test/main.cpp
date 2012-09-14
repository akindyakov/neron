#include <iostream>
#include <list>
#include "include/geometry.h"

using namespace std;

void showPoints(const std::list<Geometry::Point2f>& pts)
{
   if ( pts.empty() )
   {
      std::cout << "   " << "match!\n";
      return;
   }
   for (std::list<Geometry::Point2f>::const_iterator vecIt = pts.begin();
         vecIt != pts.end(); ++vecIt)
   {
      std::cout << "   " << " x: " << vecIt->x << " y: " << vecIt->y << std::endl;
   }
}

int main()
{
   Geometry::Point2f pt0(0,0);
   Geometry::Point2f pt1(10,0);
   Geometry::Point2f pt2(10,10);
   Geometry::Point2f pt3(0, 10);
   Geometry::Point2f pt4(9.9, 10);

   Geometry::Line_2d line1(pt0, pt1);
   Geometry::Line_2d line2(pt2, pt3);

   Geometry::Line_2d line3(pt1, pt2);
   Geometry::Line_2d line4(pt0, pt3);

   Geometry::Line_2d line5(pt0, pt2);
   Geometry::Line_2d line6(pt1, pt3);

   Geometry::Line_2d line7(pt1, pt4);


   std::list<Geometry::Point2f> pts;

   if ( Geometry::shapeIntersection(line1,line2,&pts) )
   {
      cout << "yes\n";
      showPoints(pts);
      pts.clear();
   }
   else
      cout << "no\n";

   if ( Geometry::shapeIntersection(line3,line4,&pts) )
   {
      cout << "yes\n";
      showPoints(pts);
      pts.clear();
   }
   else
      cout << "no\n";

   if ( Geometry::shapeIntersection(line5,line6,&pts) )
   {
      cout << "yes\n";
      showPoints(pts);
      pts.clear();
   }
   else
      cout << "no\n";

   if ( Geometry::shapeIntersection(line5,line5,&pts) )
   {
      cout << "yes\n";
      showPoints(pts);
      pts.clear();
   }
   else
      cout << "no\n";

   if ( Geometry::shapeIntersection(line7,line4,&pts) )
   {
      cout << "yes\n";
      showPoints(pts);
      pts.clear();
   }
   else
      cout << "no\n";

   std::list<Geometry::Point2f> rand_list = Geometry::getRandomPointCloud(45, Geometry::Point2f(0,0), Geometry::Point2f(100,100));
   for (std::list<Geometry::Point2f>::iterator it = rand_list.begin();
         it != rand_list.end(); ++it)
   {
      std::cout << "x: " << it->x << ";   y: " << it->y << std::endl;
   }
   cout << "Hello world!" << endl;
   Geometry::Circle(Geometry::Point2f(0,0), 4);
   return 0;
}
