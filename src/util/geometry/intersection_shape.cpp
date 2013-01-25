/**
 ** autor   Alexander K
 ** date    08.07.2012.13.33
 ** BRIEF   intersection implementation
*/

//=============================================================================
#include <iostream>
#include <typeinfo>
#include <iterator>
#include <cmath>
#include <algorithm>
//=============================================================================
#include "include/util/geometry/geometry.h"
#include "include/util/math/math.h"
//=============================================================================

namespace G = Geometry;

int G::shapeIntersection(const G::Circle& circ1,
                         const G::Circle& circ2,
                         std::list<G::Point2f>* genPoint)
{
   //if center1 are inside circle2
   if ( circ2.insidePoint( circ1.m_center ) )
   {
      float c1c2 = Geometry::distance(circ1.m_center, circ2.m_center);
      if ( c1c2 + circ2.m_radius < circ1.m_radius)
         return Geometry::SHAPE_NOT_INTERSECTION;
   }

   if ( circ1.insidePoint(circ2.m_center) )
   {
      float c1c2 = Geometry::distance(circ1.m_center, circ2.m_center);
      if ( c1c2 + circ1.m_radius < circ2.m_radius)
         return Geometry::SHAPE_NOT_INTERSECTION;
   }

   if ( Math::equal(circ1.m_radius, circ2.m_radius)
         && Math::equal(circ1.m_center.x, circ2.m_center.x)
         && Math::equal(circ1.m_center.y, circ2.m_center.y) )
   {
      Geometry::Point2f centerPoint(circ1.m_center);
      std::vector<float> xs;
      std::vector<float> ys;

      circ1.getX(centerPoint.y, &xs);
      circ1.getY(centerPoint.x, &ys);

      genPoint->push_back(Geometry::Point2f(xs[0], centerPoint.y));
      genPoint->push_back(Geometry::Point2f(xs[1], centerPoint.y));
      genPoint->push_back(Geometry::Point2f(centerPoint.x, ys[0]));
      genPoint->push_back(Geometry::Point2f(centerPoint.x, ys[1]));
      return Geometry::SHAPE_INTERSECTION;
   }
   return G::SHAPE_NOT_INTERSECTION;
}

int G::shapeIntersection(const G::Line_2d& line1,
                         const G::Line_2d& line2,
                         std::list<G::Point2f>* genPoint)
{
   float determ = line1.m_direct_vector.y * line2.m_direct_vector.x -
                  line1.m_direct_vector.x * line2.m_direct_vector.y;
   if ( Math::equal(determ,0) )
   {
      float vect_proud =
            (line1.m_center.x-line2.m_center.x)*line1.m_direct_vector.y -
            (line1.m_center.y-line2.m_center.y)*line1.m_direct_vector.x;

      if ( Math::equal(vect_proud,0) )
      {
         return Geometry::SHAPE_MATCH;
      }
      return Geometry::SHAPE_NOT_INTERSECTION;
   }

   if ( genPoint != NULL )
   {
      float determ1 = line1.m_direct_vector.x
                           * (line2.m_direct_vector.x * line2.m_center.y
                              - line2.m_direct_vector.y * line2.m_center.x
                              - line2.m_direct_vector.x * line1.m_center.y)
                      + line1.m_direct_vector.y
                        * line2.m_direct_vector.x
                        * line1.m_center.x;

      float determ2 = - line1.m_direct_vector.y
                           * (line2.m_direct_vector.y * line2.m_center.x
                              - line2.m_direct_vector.x * line2.m_center.y)
                      - line1.m_direct_vector.x
                           * line2.m_direct_vector.y
                           * line1.m_center.y
                      + line1.m_direct_vector.y
                           * line2.m_direct_vector.y
                           * line1.m_center.x;
      float x_cross = determ1/determ;
      float y_cross = determ2/determ;
      genPoint->push_back(Geometry::Point2f(x_cross, y_cross));
      /*
      std::cout << "  line1.m_center.x: " << line1.m_center.x
                << "  line1.m_center.y: " << line1.m_center.y
                << "\n  line1.m_direct_vector.x: " << line1.m_direct_vector.x
                << "  line1.m_direct_vector.y: " << line1.m_direct_vector.y
                << "\n  line2.m_center.x: " << line2.m_center.x
                << "  line2.m_center.y: " << line2.m_center.y
                << "\n  line2.m_direct_vector.x: " << line2.m_direct_vector.x
                << "  line2.m_direct_vector.y: " << line2.m_direct_vector.y
                <<"\n";
      std::cout << "x: " << x_cross << "y: " << y_cross << "\n";
      std::cout << "determ: " << determ << "\n";
      std::cout << "determ1: " << determ1 << "\n";
      std::cout << "determ2: " << determ2 << "\n";
      */
   }
   return Geometry::SHAPE_INTERSECTION;
}

int Geometry::shapeIntersection(const Geometry::Interval& inl1,
                                const Geometry::Interval& inl2,
                                std::list<Geometry::Point2f>* genPoint)
{
   Geometry::Line_2d line1(inl1.m_center, inl1.m_vector);
   Geometry::Line_2d line2(inl2.m_center, inl2.m_vector);
   std::list<Geometry::Point2f> lineCrossPoint;
   int ret = Geometry::shapeIntersection(line1, line2, &lineCrossPoint);

   if ( ret == SHAPE_INTERSECTION )
   {
      Geometry::Point2f cross_pt(lineCrossPoint.front());

      float temp_x = std::max(std::min(inl1.getFirst().x, inl1.getSecond().x),
                              std::min(inl2.getFirst().x, inl2.getSecond().x) );
      float temp_y = std::max(std::min(inl1.getFirst().y, inl1.getSecond().y),
                              std::min(inl2.getFirst().y, inl2.getSecond().y) );
      Geometry::Point2f lowPtBorder(temp_x,temp_y);

      temp_x = std::min(std::max(inl1.getFirst().x, inl1.getSecond().x),
                        std::max(inl2.getFirst().x, inl2.getSecond().x) );
      temp_y = std::min(std::max(inl1.getFirst().y, inl1.getSecond().y),
                        std::max(inl2.getFirst().y, inl2.getSecond().y) );
      Geometry::Point2f hiPtBorder(temp_x,temp_y);

      if ( cross_pt.x > lowPtBorder.x
           && cross_pt.x < hiPtBorder.x
           && cross_pt.y > lowPtBorder.y
           && cross_pt.y < hiPtBorder.y )
      {
         if ( genPoint != NULL )
            genPoint->swap(lineCrossPoint);
         return Geometry::SHAPE_INTERSECTION;
      }
      else
      {
         return Geometry::SHAPE_NOT_INTERSECTION;
      }
   }
   else
   {
      return ret;
   }
}

int G::shapeIntersection(const G::Contour&,
                         const G::Contour&,
                         std::list<G::Point2f>* genPoint)
{
   return G::SHAPE_NOT_INTERSECTION;
}

int borderCriterionIntersectionContour( const Geometry::Convex_contour& cont1,
                                       const Geometry::Convex_contour& cont2 )
{
   std::list<Geometry::Reduced_vector>::const_iterator ct1_listIt = cont1.m_vec.begin();
   Geometry::Reduced_vector alien_vector = *ct1_listIt;
   ++ct1_listIt;
   float vec_mod_proud = alien_vector.vector_proud(*ct1_listIt);
   --ct1_listIt;
   Geometry::Point2f basePt(cont1.m_center);
   for ( ; ct1_listIt != cont1.m_vec.end(); ++ct1_listIt )
   {
      Geometry::Point2f alienPt(cont2.m_center);
      for ( std::list<Geometry::Reduced_vector>::const_iterator ct2_listIt
                                         = cont2.m_vec.begin();; ++ct2_listIt )
      {
         if ( ct2_listIt == cont2.m_vec.end() )
            return Geometry::SHAPE_NOT_INTERSECTION;

         float current_proud =
            ct1_listIt->vector_proud(Geometry::Reduced_vector(alienPt,basePt));
         if ( current_proud*vec_mod_proud > 0 )
            break;

         alienPt = alienPt + *ct2_listIt;
      }
      basePt = basePt + *ct1_listIt;
   }
   return Geometry::SHAPE_INTERSECTION;
}

void findPointsIntersection( const Geometry::Convex_contour& cont1,
                             const Geometry::Convex_contour& cont2,
                             std::list<Geometry::Point2f>* genPoint )
{
   Geometry::Point2f firstBasePt;
   Geometry::Point2f firstNextPt(cont1.m_center);
   for ( std::list<Geometry::Reduced_vector>::const_iterator ct1_listIt
                                                 = cont1.m_vec.begin();
         ct1_listIt != cont1.m_vec.end(); ++ct1_listIt )
   {
      firstBasePt = firstNextPt;
      firstNextPt = firstNextPt + *ct1_listIt;
      //firstNextPt = Geometry::Point2f(1,1) + Geometry::Reduced_vector(0,0);
      Geometry::Interval firstInterval(firstBasePt,firstNextPt);

      Geometry::Point2f secondBasePt;
      Geometry::Point2f secondNextPt(cont2.m_center);
      for ( std::list<Geometry::Reduced_vector>::const_iterator ct2_listIt
                                                    = cont2.m_vec.begin();
            ct2_listIt != cont2.m_vec.end(); ++ct2_listIt )
      {
         secondBasePt = secondNextPt;
         secondNextPt = secondNextPt + Geometry::Reduced_vector(1,1);//*ct2_listIt;
         Geometry::Interval secondInterval(secondBasePt, secondNextPt);
         Geometry::shapeIntersection(firstInterval, secondInterval, genPoint);
      }
   }
   if ( genPoint->size() == 0 )
      throw Geometry::Geometry_error("Not found the points of restraint in the intersecting shapes");
}

int Geometry::shapeIntersection(const Geometry::Convex_contour& cont1,
                                const Geometry::Convex_contour& cont2,
                                std::list<Point2f>* genPoint)
{
   if ( borderCriterionIntersectionContour(cont1,cont2) )
   {
      if ( borderCriterionIntersectionContour(cont2,cont1) )
      {
         if ( genPoint != NULL )
            findPointsIntersection(cont1, cont2, genPoint);
      }
      else
         return Geometry::SHAPE_NOT_INTERSECTION;
   }
   else
      return Geometry::SHAPE_NOT_INTERSECTION;

   return Geometry::SHAPE_INTERSECTION;
}

int G::shapeIntersection(const G::Circle& circ,
                         const G::Line_2d& line,
                         std::list<G::Point2f>* genPoint)
{
   G::Point2f half_hord_pt;
   float dist = line.getDistance(circ.m_center, &half_hord_pt);
   int ret = G::SHAPE_NOT_INTERSECTION;
   if (dist > circ.m_radius)
      return ret;
   else
   {
      ret = G::SHAPE_INTERSECTION;
      if ( genPoint == NULL )
         return ret;
   }
   float half_hord = std::sqrt(circ.m_radius*circ.m_radius - dist*dist);
   G::Reduced_vector line_direct(line.m_direct_vector);
   line_direct.set_lenght(half_hord);
   genPoint->push_back(half_hord_pt + line_direct);
   genPoint->push_back(half_hord_pt + (-line_direct));
   return ret;
}

int G::shapeIntersection(const G::Circle& circ,
                         const G::Interval& interval,
                         std::list<G::Point2f>* genPoint)
{
   std::list<G::Point2f> lineGenPoint;
   int ret = G::shapeIntersection(circ, interval, &lineGenPoint);
   if (ret != G::SHAPE_INTERSECTION)
   {
      return ret;
   }
   ret = G::SHAPE_NOT_INTERSECTION;
   if ( interval.belongRectangleArea(lineGenPoint.front()) )
   {
      ret = G::SHAPE_INTERSECTION;
      if ( genPoint != NULL )
         genPoint->push_back(lineGenPoint.front());
      else
         return ret;
   }
   if (  lineGenPoint.size() > 1
      && interval.belongRectangleArea(lineGenPoint.back()) )
   {
      if ( genPoint != NULL )
         genPoint->push_back(lineGenPoint.back());
      ret = G::SHAPE_INTERSECTION;
   }
   return ret;
}

int G::shapeIntersection(const G::Circle&,
                         const G::Contour&,
                         std::list<G::Point2f>* genPoint)
{
   return G::SHAPE_NOT_INTERSECTION;
}

int G::shapeIntersection(const G::Circle& circ,
                         const G::Convex_contour& conv_cont,
                         std::list<G::Point2f>* genPoint)
{
   G::Point2f pt = conv_cont.m_center;
   if ( genPoint != NULL )
   {
      // if need to find points of intersection
      // we must check all over intervals
      for (std::list<G::Reduced_vector>::const_iterator ptIt = conv_cont.m_vec.begin();
            ptIt != conv_cont.m_vec.end();
            ++ptIt)
      {
         G::shapeIntersection(circ, G::Interval(pt, *ptIt), genPoint);
         pt = pt + *ptIt;
      }
      if ( genPoint->size() > 0 )
         return G::SHAPE_INTERSECTION;
      else
         return G::SHAPE_NOT_INTERSECTION;
   }
   else
   {
      // if not need to find intersection points
      // it is enought to find at list one intersection point

      int rez = G::SHAPE_NOT_INTERSECTION;
      for (std::list<G::Reduced_vector>::const_iterator ptIt = conv_cont.m_vec.begin();
            ( rez == G::SHAPE_NOT_INTERSECTION && ptIt != conv_cont.m_vec.end() );
            ++ptIt)
      {
         rez = G::shapeIntersection(circ, G::Interval(pt, *ptIt), genPoint);
         pt = pt + *ptIt;
      }
      return rez;
   }
}

int G::shapeIntersection(const G::Line_2d& line,
                         const G::Interval& interval,
                         std::list<G::Point2f>* genPoint)
{
   std::list<G::Point2f> lineGenPoint;
   int ret = G::shapeIntersection(line, G::Line_2d(interval), &lineGenPoint);
   if (ret == G::SHAPE_INTERSECTION)
   {
      if ( interval.belongRectangleArea(lineGenPoint.front()) )
      {
         if ( genPoint != NULL )
            genPoint->push_back(lineGenPoint.front());
      }
      else
         ret = G::SHAPE_NOT_INTERSECTION;
   }

   return ret;
}

int G::shapeIntersection(const G::Line_2d&,
                         const G::Contour&,
                         std::list<G::Point2f>* genPoint)
{
   return G::SHAPE_NOT_INTERSECTION;
}

int G::shapeIntersection(const G::Line_2d& line,
                         const G::Convex_contour& conv_cont,
                         std::list<G::Point2f>* genPoint)
{
   G::Point2f pt = conv_cont.m_center;
   if ( genPoint != NULL )
   {
      // if need to find points of intersection
      // we must check all over intervals
      for (std::list<G::Reduced_vector>::const_iterator ptIt = conv_cont.m_vec.begin();
            ptIt != conv_cont.m_vec.end();
            ++ptIt)
      {
         G::shapeIntersection(line, G::Interval(pt, *ptIt), genPoint);
         pt = pt + *ptIt;
      }
      if ( genPoint->size() > 0 )
         return G::SHAPE_INTERSECTION;
      else
         return G::SHAPE_NOT_INTERSECTION;
   }
   else
   {
      // if not need to find intersection points
      // it is enought to find at list one intersection point

      int rez = G::SHAPE_NOT_INTERSECTION;
      for (std::list<G::Reduced_vector>::const_iterator ptIt = conv_cont.m_vec.begin();
            ( rez == G::SHAPE_NOT_INTERSECTION && ptIt != conv_cont.m_vec.end() );
            ++ptIt)
      {
         rez = G::shapeIntersection(line, G::Interval(pt, *ptIt), genPoint);
         pt = pt + *ptIt;
      }
      return rez;
   }
}

int G::shapeIntersection(const G::Interval&,
                         const G::Contour&,
                         std::list<G::Point2f>* genPoint)
{
   return G::SHAPE_NOT_INTERSECTION;
}

int G::shapeIntersection(const G::Interval& interval,
                         const G::Convex_contour& conv_cont,
                         std::list<G::Point2f>* genPoint)
{
   G::Point2f pt = conv_cont.m_center;
   if ( genPoint != NULL )
   {
      // if need to find points of intersection
      // we must check all over intervals
      for (std::list<G::Reduced_vector>::const_iterator ptIt = conv_cont.m_vec.begin();
            ptIt != conv_cont.m_vec.end();
            ++ptIt)
      {
         G::shapeIntersection(G::Interval(pt, *ptIt), interval, genPoint);
         pt = pt + *ptIt;
      }
      if ( genPoint->size() > 0 )
         return G::SHAPE_INTERSECTION;
      else
         return G::SHAPE_NOT_INTERSECTION;
   }
   else
   {
      // if not need to find intersection points
      // it is enought to find at list one intersection point

      int rez = G::SHAPE_NOT_INTERSECTION;
      for (std::list<G::Reduced_vector>::const_iterator ptIt = conv_cont.m_vec.begin();
            ( rez == G::SHAPE_NOT_INTERSECTION && ptIt != conv_cont.m_vec.end() );
            ++ptIt)
      {
         rez = G::shapeIntersection(G::Interval(pt, *ptIt), interval, genPoint);
         pt = pt + *ptIt;
      }
      return rez;
   }
}

int G::shapeIntersection(const G::Contour&,
                         const G::Convex_contour&,
                         std::list<G::Point2f>* genPoint)
{
   return G::SHAPE_NOT_INTERSECTION;
}

int G::shapeIntersection(const G::I_Shape& shape1,
                         const G::I_Shape& shape2,
                         std::list<Point2f>* genPoint)
{
   const G::Circle * circle = &dynamic_cast<const G::Circle&>( shape1 );
   if ( circle )
      return G::shapeIntersection( *circle, shape2, genPoint );

   const G::Line_2d * line = &dynamic_cast<const G::Line_2d&>( shape1 );
   if ( line )
      return G::shapeIntersection(*line, shape2, genPoint );

   const G::Interval * interval = &dynamic_cast<const G::Interval&>( shape1 );
   if ( interval )
      return G::shapeIntersection(*interval, shape2, genPoint);

   const G::Contour * cont = &dynamic_cast<const G::Contour&>( shape1 );
   if (cont)
      return G::shapeIntersection(*cont, shape2, genPoint);

   const G::Convex_contour * conv_cont
                        = &dynamic_cast<const G::Convex_contour&>( shape1 );
   if (conv_cont)
      return G::shapeIntersection(*conv_cont, shape2, genPoint);

   throw Geometry::Geometry_error(
      "Not defined type - was not reognized in dynamic intersection");
}

int G::shapeIntersection( const G::Circle& circ,
                          const G::I_Shape& shape,
                          std::list<G::Point2f>* genPoint )
{
   const G::Circle * circle = &dynamic_cast<const G::Circle&>( shape );
   if ( circle )
      return G::shapeIntersection( *circle, circ, genPoint );

   const G::Line_2d * line = &dynamic_cast<const G::Line_2d&>( shape );
   if ( line )
      return G::shapeIntersection( circ, *line, genPoint );

   const G::Interval * interval = &dynamic_cast<const G::Interval&>( shape );
   if ( interval )
      return G::shapeIntersection(circ, *interval, genPoint);

   const G::Contour * cont = &dynamic_cast<const G::Contour&>( shape );
   if (cont)
      return G::shapeIntersection(circ, *cont, genPoint);

   const G::Convex_contour * conv_cont
                        = &dynamic_cast<const G::Convex_contour&>( shape );
   if (conv_cont)
      return G::shapeIntersection(circ, *conv_cont, genPoint);

   throw Geometry::Geometry_error(
      "Not defined type - was not reognized in dynamic intersection");
}

int G::shapeIntersection(const G::Line_2d& line,
                         const G::I_Shape& shape,
                         std::list<G::Point2f>* genPoint)
{
   const G::Circle * circle = &dynamic_cast<const G::Circle&>( shape );
   if ( circle )
      return G::shapeIntersection( *circle, line, genPoint );

   const G::Line_2d * line2 = &dynamic_cast<const G::Line_2d&>( shape );
   if ( line2 )
      return G::shapeIntersection( *line2, line, genPoint );

   const G::Interval * interval = &dynamic_cast<const G::Interval&>( shape );
   if ( interval )
      return G::shapeIntersection(line, *interval, genPoint);

   const G::Contour * cont = &dynamic_cast<const G::Contour&>( shape );
   if (cont)
      return G::shapeIntersection(line, *cont, genPoint);

   const G::Convex_contour * conv_cont
                        = &dynamic_cast<const G::Convex_contour&>( shape );
   if (conv_cont)
      return G::shapeIntersection(line, *conv_cont, genPoint);

   throw Geometry::Geometry_error(
      "Not defined type - was not reognized in dynamic intersection");
}

int G::shapeIntersection(const G::Interval& interval,
                         const G::I_Shape& shape,
                         std::list<G::Point2f>* genPoint)
{
   const G::Circle * circle = &dynamic_cast<const G::Circle&>( shape );
   if ( circle )
      return G::shapeIntersection(*circle, interval, genPoint );

   const G::Line_2d * line = &dynamic_cast<const G::Line_2d&>( shape );
   if ( line )
      return G::shapeIntersection(*line, interval, genPoint );

   const G::Interval * interval_pt = &dynamic_cast<const G::Interval&>( shape );
   if ( interval_pt )
      return G::shapeIntersection(*interval_pt, interval, genPoint);

   const G::Contour * cont = &dynamic_cast<const G::Contour&>( shape );
   if (cont)
      return G::shapeIntersection(interval, *cont, genPoint);

   const G::Convex_contour * conv_cont
                        = &dynamic_cast<const G::Convex_contour&>( shape );
   if (conv_cont)
      return G::shapeIntersection(interval, *conv_cont, genPoint);

   throw Geometry::Geometry_error(
      "Not defined type - was not reognized in dynamic intersection");
}

int G::shapeIntersection(const G::Contour& cont,
                         const G::I_Shape& shape,
                         std::list<G::Point2f>* genPoint)
{
   const G::Circle * circle = &dynamic_cast<const G::Circle&>( shape );
   if ( circle )
      return G::shapeIntersection(*circle, cont, genPoint );

   const G::Line_2d * line = &dynamic_cast<const G::Line_2d&>( shape );
   if ( line )
      return G::shapeIntersection(*line, cont, genPoint );

   const G::Interval * interval = &dynamic_cast<const G::Interval&>( shape );
   if ( interval )
      return G::shapeIntersection(*interval, cont, genPoint);

   const G::Contour * cont_pt = &dynamic_cast<const G::Contour&>( shape );
   if (cont_pt)
      return G::shapeIntersection(*cont_pt, cont, genPoint);

   const G::Convex_contour * conv_cont
                        = &dynamic_cast<const G::Convex_contour&>( shape );
   if (conv_cont)
      return G::shapeIntersection(cont, *conv_cont, genPoint);

   throw Geometry::Geometry_error(
      "Not defined type - was not reognized in dynamic intersection");
}

int G::shapeIntersection(const G::Convex_contour& conv_cont,
                         const G::I_Shape& shape,
                         std::list<G::Point2f>* genPoint)
{
   const G::Circle * circle = &dynamic_cast<const G::Circle&>( shape );
   if ( circle )
      return G::shapeIntersection(*circle, conv_cont, genPoint );

   const G::Line_2d * line = &dynamic_cast<const G::Line_2d&>( shape );
   if ( line )
      return G::shapeIntersection(*line, conv_cont, genPoint );

   const G::Interval * interval = &dynamic_cast<const G::Interval&>( shape );
   if ( interval )
      return G::shapeIntersection(*interval, conv_cont, genPoint);

   const G::Contour * cont = &dynamic_cast<const G::Contour&>( shape );
   if (cont)
      return G::shapeIntersection(*cont, conv_cont, genPoint);

   const G::Convex_contour * conv_cont_pt
                        = &dynamic_cast<const G::Convex_contour&>( shape );
   if (conv_cont_pt)
      return G::shapeIntersection(*conv_cont_pt, conv_cont, genPoint);

   throw Geometry::Geometry_error(
      "Not defined type - was not reognized in dynamic intersection");
}
