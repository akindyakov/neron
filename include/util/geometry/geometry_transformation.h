/**
 ** autor   Alexander K
 ** date    01.02.2012.19.23
 ** BRIEF   geometry transform function
*/

#ifndef GEOMETRY_TRANSFORMATION_H
#define GEOMETRY_TRANSFORMATION_H
//=============================================================================
#include <vector>
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

namespace Geometry
{
   void createShadow  ( const Convex_contour& src_contour, 
                        std::vector< Convex_contour >* out_contour,
                        const std::vector< Reduced_vector >& start_points );
}

#endif //GEOMETRY_TRANSFORMATION_H
