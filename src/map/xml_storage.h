/**
 ** autor   Alexander K
 ** date    03.03.2013.00.34
 ** BRIEF   
*/

#ifndef XML_MAP_STORAGE
#define XML_MAP_STORAGE

//=============================================================================
//=============================================================================
//=============================================================================
#include "include/map/map.h"

namespace Map
{
namespace XmlStorage
{
   void saveMapToXmlFile(int file ,const MapContainer& map);
}
}

#endif //XML_MAP_STORAGE
