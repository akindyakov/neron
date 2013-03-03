/**
 ** autor   Alexander K
 ** date    23.02.2012.23.15
 ** BRIEF   path util
*/

#ifndef MAP_PATH_UTIL_H
#define MAP_PATH_UTIL_H
//=============================================================================
#include <vector>
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

namespace Map
{
   class MapPath
   {
   public:
      MapPath();
      int getWeight();
      int setWeight();
      
      int getFrequency();
      int incrementFrequency();
      
   private:
      int m_weight;
      int m_usingFrequensy;
      Geometry::Contour m_path;
      Geometry::Reduced_vector m_width;
   };
   
   class PathHash
   {
   public:
      PathHash();
      std::vector< MapPath > getPath(int,int);
   private:
   };
   
   //transformPathForDifferentialDrive ( const MapPath& srcPath );
}

#endif //MAP_PATH_UTIL_H
