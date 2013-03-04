/**
 ** autor   Alexander K
 ** date    03.03.2013.00.34
 ** BRIEF   
*/

#ifndef XML_MAP_STORAGE
#define XML_MAP_STORAGE

//=============================================================================
#include <string>
//=============================================================================
#include "include/map/map.h"
#include "other/tinyxml/tinyxml.h"
//=============================================================================

using namespace Map::XmlStorage;

void saveMapToXmlFile(std::string file_name, const MapContainer& map)
{
   TiXmlDocument doc(file_name);
   TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "1", "2");
   TiXmlElement * element = new TiXmlElement("MapContainer");
   
   doc.linkEndChild( decl );
   doc.LinkEndChild( element );
   doc.SaveFile();
   
   delete dec;
   delete element;
}

#endif //XML_MAP_STORAGE
