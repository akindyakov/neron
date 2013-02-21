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
  
   class I_Gate
   {
   public:
      boost::shared_ptr<I_MapCell> getOut();
      int getKey();
   private:
      int m_outMapKey;
      boost::shared_ptr<I_MapCell> m_outCell;
   };
   
   class vectorGate: public I_Gate
   {
   public:
      
   private:
      Geometry::Reduced_vector m_halfWideVector;
      Geometry::Point2f m_gateCenter;
   };
   
   class Portal
   {
   public:
      
   private:
      boost::shared_ptr< I_Gate > m_firstGate;
      boost::shared_ptr< I_Gate > m_secondGate;
   };
   
   class MapPath
   {
   public:
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
      std::vector< MapPath > getPath(int,int);
   private:
   };
   
   class VectorMapCell: public I_MapCell
   {
   public:
      
   private:
      std::list< boost::shared_ptr < Portal > > m_portals;
      std::list< Geometry::Contour > m_borders;
      PathHash m_paths;
   };
   
   class RasterMapCell: public I_MapCell
   {
   public:
      RasterMapCell(int lenght, int width);
   private:
      std::list< boost::shared_ptr < Portal > > m_portals;
      cv::Map m_location;
   };
   
   class MapContainer: public I_MapCell
   {
   public:
      
   private:
      std::vector< boost::shared_ptr<I_MapCell> > m_parts;
   };
}

#endif //MAP_H
