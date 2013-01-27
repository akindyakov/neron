/**
 ** autor   Alexander K
 ** date    30.06.2012.21.56
 ** BRIEF   
*/

#ifndef MAP_H
#define MAP_H
//=============================================================================
#include <vector>
//=============================================================================
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
   
   class Cell_portal
   {
   public:
   private:
   };  
   
   class VectorMapCell: public I_MapCell
   {
   public:
      VectorMapCell(int lenght, int width);
      
      void addPortal();
      
   private:
      std::vector<Map::Cell_portal> m_input_output;
      std::vector<Geometry::I_Shape> m_obstacles;
   };
   
   class RasterMapCell: public I_MapCell
   {
   public:
      RasterMapCell(int lenght, int width);
      
      void addPortal();
   private:
      std::vector< std::vector< int > > m_map;
      std::vector<Map::Cell_portal> m_input_output;
   };
}

#endif //MAP_H
