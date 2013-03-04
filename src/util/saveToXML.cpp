/**
 ** autor   Alexander K
 ** date    05.03.2013.01.01
 ** BRIEF   
*/

#ifndef SAVE_TO_TINYXML_H
#define SAVE_TO_TINYXML_H

//=============================================================================
#include <string>
//=============================================================================
#include "include/util/saveToXML.h"
//=============================================================================

TiXmlElement* NeronXML::saveToXmlElement(const Reduced_vector&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Point2f&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Reduced_vector&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Circle&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Interval&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Line_2d&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Convex_contour&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Contour&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const vectorGate&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const Portal&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const VectorMapCell&)
{
   return new TiXmlElement("");
}

TiXmlElement* NeronXML::saveToXmlElement(const MapContainer&)
{
   return new TiXmlElement("");
}


#endif SAVE_TO_TINYXML_H
