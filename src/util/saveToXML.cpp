/**
 ** autor   Alexander K
 ** date    05.03.2013.01.01
 ** BRIEF   
*/

//=============================================================================
#include <string>
//=============================================================================
#include "include/util/saveToXML.h"
//=============================================================================

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Point2f& pt)
{
   TiXmlElement* savePt = new TiXmlElement("Point2f");
   savePt->SetDoubleAttribute("x", pt.x);
   savePt->SetDoubleAttribute("y", pt.y);
   return savePt;
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Reduced_vector& vec)
{
   TiXmlElement* saveVec = new TiXmlElement("Point2f");
   saveVec->SetDoubleAttribute("x", vec.x);
   saveVec->SetDoubleAttribute("y", vec.y);
   return saveVec;
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Circle& circ)
{
   TiXmlElement* saveCirc = new TiXmlElement("Circle");
   saveCirc->LinkEndChild( saveToXmlElement(circ.m_center) );
   saveCirc->SetDoubleAttribute("radius", circ.m_radius);
   return saveCirc;
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Interval& interval)
{
   return new TiXmlElement("Interval");
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Line_2d& line)
{
   return new TiXmlElement("Line_2d");
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Convex_contour& cCont)
{
   return new TiXmlElement("Convex_contour");
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Contour& cont)
{
   return new TiXmlElement("Contour");
}

TiXmlElement* NeronXML::saveToXmlElement(const Map::vectorGate& vgate)
{
   return new TiXmlElement("vectorGate");
}

TiXmlElement* NeronXML::saveToXmlElement(const Map::Portal& port)
{
   return new TiXmlElement("Portal");
}

TiXmlElement* NeronXML::saveToXmlElement(const Map::VectorMapCell& cell)
{
   return new TiXmlElement("VectorMapCell");
}

TiXmlElement* NeronXML::saveToXmlElement(const Map::MapContainer& map)
{
   return new TiXmlElement("MapContainer");
}
