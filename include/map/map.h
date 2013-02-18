/**
 ** autor   Alexander K
 ** date    30.06.2012.21.56
 ** BRIEF   
*/

#ifndef MAP_H
#define MAP_H
//=============================================================================
#include <vector>
#include <boost/shared_ptr.hpp>
//=============================================================================
#include "include/util/geometry/geometry.h"
//=============================================================================

namespace Map
{
   class I_MapCell
   {
   public:
      virtual void addPortal();
   private:
   };
   
   class Portal_gate
   {
   public:
      
   private:
      boost::shared_ptr<I_MapCell> m_firstOut;
      boost::shared_ptr<I_MapCell> m_secondOut;
      Geometry::Reduced_vector m_halfWideVector;
      Geometry::Point2f m_gateCenter;
   };
   
   class VectorMapCell: public I_MapCell
   {
   public:
      //VectorMapCell(int lenght, int width);
      
      void addPortal();
      
   private:
   };
   
   class RasterMapCell: public I_MapCell
   {
   public:
      RasterMapCell(int lenght, int width);
      
      void addPortal();
   private:
      std::vector< std::vector< int > > m_map;
   };


   class MapContainer: public I_MapCell
   {
   public:
      
   private:
      std::vector< boost::shared_ptr<I_MapCell> > m_parts;
   };
}

#endif //MAP_H
