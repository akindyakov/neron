/**
 ** autor   Alexander K
 ** date    04.03.2013.23.24
 ** BRIEF   
*/

//=============================================================================
#include <iostream>
#include <cmath>
//=============================================================================
#include "include/map/map.h"
#include "include/map/map_path.h"
//=============================================================================

using namespace std;

int main ()
{
   cout << "Neron Test : creating and saving to xml file map";
   std::vector<double> test;
   
   for (int i=0; i < 100; ++i)
      test.push_back(i*M_PI);
      
   Map::MapContainer simple_map(test);
   
   saveMapToXmlFile( "map_save.xml", simple_map);
   return 0;
}
