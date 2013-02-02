/**
 ** autor   Alexander K
 ** date    01.02.2012.19.23
 ** BRIEF   geometry transform function
*/

#ifndef GEOMETRY_TRANSFORMATION_H
#define GEOMETRY_TRANSFORMATION_H
//=============================================================================
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

namespace Geometry
{
   void createShadow  ( const Convex_contour& src_cont, 
                        Convex_contour* out_neg_cont,
                        Convex_contour* out_pos_cont,
                        float dstance  );
   
   void createShadow  ( const Contour& src_cont,
                        Contour* out_neg_cont,
                        Contour* out_pos_cont,
                        float dstance  );
   
   // side = -1 or 1 - this mean a sign of vector multiply
   void createOneSideShadow ( const Convex_contour& src_cont, 
                              Convex_contour* out_cont,
                              float distance, 
                              int side=1  );
   
   void createOneSideShadow ( const Contour& src_cont, 
                              Contour* out_cont,
                              float distance, 
                              int side=1  );
} 
