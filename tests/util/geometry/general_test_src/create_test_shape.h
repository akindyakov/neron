/**
 ** autor   Alexander K
 ** date    11.02.2013.22.34
 ** BRIEF   generating function of simple test figure
*/

//=============================================================================
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

Geometry::Convex_contour createCircleContour( const Geometry::Point2f& center,
                                              float radius, int detalisation);

Geometry::Convex_contour createAngleContour( const Geometry::Point2f& m_start,
                                             float lenght   );
