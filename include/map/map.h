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
      int m_width;
      int m_lenght;
   };
   class Portal_gate
   {
   public:
      
   private:
      boost::shared_ptr<I_MapCell> m_out;
      boost::shared_ptr<Geometry::I_Shape> m_firstDoorPost;
      boost::shared_ptr<Geometry::I_Shape> m_secondDoorPost;
   };
   
   class Cell_portal
   {
   public:
   private:
      std::list< Portal_gate > m_gates;
   };  
   
   class VectorMapCell: public I_MapCell
   {
   public:
      VectorMapCell(int lenght, int width);
      
      void addPortal();
      
   private:
      std::vector<Map::Cell_portal> m_input_output;
      std::vector<Geometry::I_Shape*> m_obstacles;
   };
   
   class RasterMapCell: public I_MapCell
   {
   public:
      RasterMapCell(int lenght, int width);
      
      void addPortal();
   private:
      std::vector< std::vector< int > > m_map;
      std::vector<Map::Cell_portal> m_input_output;
      int m_width;
      int m_lenght;
   };


   class MapContainer: public I_MapCell
   {
   public:
      
   private:
      std::vector< boost::shared_ptr<I_MapCell> > m_parts;
   };
}

#endif //MAP_H
