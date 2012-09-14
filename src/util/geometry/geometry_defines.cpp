/**
 ** autor   Alexander K
 ** email   akindyakov@gmail.com
 ** date    25.08.2012.01.24
 ** BRIEF   GEOMETRY defines
*/

#ifndef GEOMETRY_DEFINES_H
#define GEOMETRY_DEFINES_H
//=============================================================================
//=============================================================================
#include "include/geometry.h"
//=============================================================================

namespace G = Geometry;

int G::I_Shape::m_type        = SHAPE;
int G::Circle::m_type         = CIRCLE;
int G::Line_2d::m_type        = LINE_2D;
int G::Interval::m_type       = INTERVAL;
int G::Convex_contour::m_type = CONVEX_CONTOUR;
int G::Contour::m_type        = CONTOUR;

#endif // GEOMETRY_DEFINES_H
