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
#include "other/inyxml/tinyxml.h"
//=============================================================================
//=============================================================================

namespace NeronXml
{
   TiXmlElement* saveToXmlElement(const Reduced_vector&);
   TiXmlElement* saveToXmlElement(const Point2f&);
   TiXmlElement* saveToXmlElement(const Reduced_vector&);
   TiXmlElement* saveToXmlElement(const Circle&);
   TiXmlElement* saveToXmlElement(const Interval&);
   TiXmlElement* saveToXmlElement(const Line_2d&);
   TiXmlElement* saveToXmlElement(const Convex_contour&);
   TiXmlElement* saveToXmlElement(const Contour&);

   TiXmlElement* saveToXmlElement(const vectorGate&);
   TiXmlElement* saveToXmlElement(const Portal&);
   TiXmlElement* saveToXmlElement(const VectorMapCell&);
   TiXmlElement* saveToXmlElement(const MapContainer&);
}

#endif SAVE_TO_TINYXML_H
