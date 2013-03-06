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
   TiXmlElement* saveInterval = new TiXmlElement("Interval");
   saveInterval->LinkEndChild( saveToXmlElement(interval.m_center) );
   saveInterval->LinkEndChild( saveToXmlElement(interval.m_vector) );
   return saveInterval;
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Line_2d& line)
{
   TiXmlElement* saveLine = new TiXmlElement("Line_2d");
   saveLine->LinkEndChild( saveToXmlElement(line.m_center) );
   saveLine->LinkEndChild( saveToXmlElement(line.m_vector) );
   return saveLine;
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Convex_contour& cCont)
{
   TiXmlElement* sv_cont = new TiXmlElement("Convex_contour");
   for ( Geometry::constReducedVectorIterator vecIt = cCont.cbeginIt();
         vecIt != cCont.cendIt(); ++vecIt)
   {
      sv_cont->LinkEndChild( saveToXmlElement(*vecIt) );
   }
   return sv_cont;
}

TiXmlElement* NeronXML::saveToXmlElement(const Geometry::Contour& cont)
{
   TiXmlElement* sv_cont = new TiXmlElement("Contour");
   for ( Geometry::constConvexContourIterator ccontIt = cont.cbeginIt();
         ccontIt != cont.cendIt(); ++ccontIt)
   {
      sv_cont->LinkEndChild( saveToXmlElement(*ccontIt) );
   }
   return sv_cont;
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
