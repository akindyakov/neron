/**
 ** autor   Alexander K
 ** date    05.03.2013.01.01
 ** BRIEF   
*/

#ifndef SAVE_TO_TINYXML_H
#define SAVE_TO_TINYXML_H

//=============================================================================
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "other/tinyxml/tinyxml.h"
//=============================================================================
#include "include/util/geometry/geometry.h"
#include "include/map/map.h"
//=============================================================================

namespace NeronXML
{
   TiXmlElement* saveToXmlElement(const Geometry::Reduced_vector&);
   TiXmlElement* saveToXmlElement(const Geometry::Point2f&);
   TiXmlElement* saveToXmlElement(const Geometry::Reduced_vector&);
   TiXmlElement* saveToXmlElement(const Geometry::Circle&);
   TiXmlElement* saveToXmlElement(const Geometry::Interval&);
   TiXmlElement* saveToXmlElement(const Geometry::Line_2d&);
   TiXmlElement* saveToXmlElement(const Geometry::Convex_contour&);
   TiXmlElement* saveToXmlElement(const Geometry::Contour&);

   TiXmlElement* saveToXmlElement(const Map::vectorGate&);
   TiXmlElement* saveToXmlElement(const Map::Portal&);
   TiXmlElement* saveToXmlElement(const Map::VectorMapCell&);
   TiXmlElement* saveToXmlElement(const Map::MapContainer&);
}

#endif //SAVE_TO_TINYXML_H
