/**
 ** autor   Alexander K
 ** date    21.06.2012.01.39
 ** BRIEF   GEOMETRY UTIL
*/

#ifndef GEOMETRY_H
#define GEOMETRY_H
//=============================================================================
#include <vector>
#include <list>
//=============================================================================
//=============================================================================

namespace Geometry
{
   template<class T> struct Point
   {
      Point();
      Point(T _x, T _y);
      Point(const Point& pt);

      T x;
      T y;
   };

   typedef Point<int> Point2i;
   typedef Point<float> Point2f;

   class Reduced_vector: public Point2f
   {
   public:
      Reduced_vector();
      Reduced_vector(float _x,float _y);
      Reduced_vector(const Point2f& pt);
      Reduced_vector(const Point2f& start_pt, const Point2f& end_pt);
      void turn(float angle);
      Reduced_vector get_perpendicular()const;
      void set_lenght(float len);
      float get_lenght()const;
      friend float operator * (const Reduced_vector& vec1, const Reduced_vector& vec2);
      float vector_proud(const Reduced_vector& vec)const;
      friend Reduced_vector operator * (const Reduced_vector&, float);
      friend Reduced_vector operator * (float, const Reduced_vector&);
      friend Reduced_vector operator + (const Reduced_vector& vec1, const Reduced_vector& vec2);
      //friend Reduced_vector operator - (const Reduced_vector& vec1, const Reduced_vector& vec2);
      friend Point2f        operator + (const Point2f& pt, const Reduced_vector& vec);
      Reduced_vector operator - ()const;
   };

   class I_Shape
   {
   public:
      I_Shape(){};
      I_Shape(const Point2f& center) : m_center(center){};

      //virtual int get_type()const = 0;
      // turning shape about m_center point
      virtual void turn(float angle)=0;
      // check point for belonging at borders shape
      // where are you want to use it
      virtual bool belongingPoint(const Point2f& point)const=0;
      virtual bool insidePoint(const Point2f& point)const
                     {return 0;};
      virtual bool shapeIntersection(const I_Shape& inputShape,
                                      std::list<Point2f>* genPoins=NULL)
                                    {return false;};
      // return distance for shape and optionaly return from close_pt close
      // points belonging shape
      virtual float getDistance(const Point2f& pt, Point2f* close_pt=NULL)const = 0;
      virtual void getX(float y, std::vector<float>* x)const{};
      virtual void getY(float x, std::vector<float>* y)const{};
      Point2f* getCenter();
   //private:
      Point2f m_center;
   };

   class Circle : public I_Shape
   {
   public:
      Circle(const Point2f& center, float radius);
      Circle(const Point2f& center, const Point2f& circlePoint);
      Circle(const Point2f& pt1, const Point2f& pt2, const Point2f& pt3);

      void create(const Point2f& center, float radius);
      void create(const Point2f& center, const Point2f& circlePoint);
      void create(const Point2f& pt1, const Point2f& pt2, const Point2f& pt3);

      void turn(float angle);
      bool belongingPoint(const Point2f& point)const;
      bool insidePoint(const Point2f& point)const;
      bool shapeIntersection(const I_Shape& inputShape,
                             std::list<Point2f>* genPoins=NULL);

      float getDistance(const Point2f& pt, Point2f* close_pt=NULL)const;

      void getX(float y, std::vector<float>* x)const;
      void getY(float x, std::vector<float>* y)const;

      // --- data ---
      float m_radius;

      private:
         static int m_type;
   };

   class Interval : public I_Shape
   {
   public:
      Interval(const Point2f& pt1, const Point2f& pt2);
      Interval(const Point2f& pt, const Reduced_vector& relative_vec);

      void turn(float angle);
      bool belongingPoint(const Point2f& point)const;
      bool shapeIntersection(const I_Shape& inputShape,
                             std::list<Geometry::Point2f>* genPoins=NULL);
      float getDistance(const Point2f& pt, Point2f* close_pt=NULL)const;
      //void getPoints(Point2f* pt1, Point2f* pt2);
      Point2f getFirst()const;
      Point2f getSecond()const;
      void getX(float y, std::vector<float>* x)const;
      void getY(float x, std::vector<float>* y)const;

      bool belongRectangleArea(const Point2f& pt)const;
      // --- data ---
      Reduced_vector m_vector;
   };

   class Line_2d : public I_Shape
   {
   public:
      Line_2d(const Point2f& pt1, const Point2f& pt2);
      Line_2d(const Interval&);
      Line_2d(const Reduced_vector& direct_vector,
              const Point2f& pt);

      //virtual ~Line_2d(){};

      //int get_type()const;

      void turn(float angle);
      bool belongingPoint(const Point2f& point)const;
      bool shapeIntersection(const I_Shape& inputShape,
                             std::list<Geometry::Point2f>* genPoins=NULL);

      float getDistance(const Point2f& pt, Point2f* close_pt=NULL)const;
      void getX(float y, std::vector<float>* x)const;
      void getY(float x, std::vector<float>* y)const;
   
      Reduced_vector m_direct_vector;
   };

   class Convex_contour : public I_Shape
   {
   public:
      Convex_contour(){};
      Convex_contour(const Point2f& center);
      Convex_contour(const Point2f& center,
                     const std::list<Reduced_vector>& polinom);
      Convex_contour(const std::list<Point2f>& polinom);
      
      virtual ~Convex_contour(){};
      
      void push_back(const Reduced_vector& pt);
      void push_back(float x, float y);
      void turn(float angle);
      bool belongingPoint(const Point2f& point)const;
      bool insidePoint(const Point2f& point)const;
      bool shapeIntersection(const I_Shape& inputShape,
                             std::list<Point2f>* genPoins=NULL);
      
      float getDistance(const Point2f& pt, Point2f* close_pt=NULL)const;
      
      Point2f getEnd();
      
      void getX(float y, std::vector<float>* x)const;
      void getY(float x, std::vector<float>* y)const;
      
      // --- data ---
      std::list<Reduced_vector> m_vec;
   };

   class Contour : public I_Shape
   {
   public:
      Contour(const Point2f& center, const std::list<Reduced_vector>& polinom);
      Contour(const std::list<Point2f>& polinom);
      
      virtual ~Contour(){};
      
      // const Point2f& getCenter();
      // const std::list<Reduced_vector>& getVectorList();
      
      void push_back(float x, float y);
      void push_back(const Reduced_vector& pt);
      void turn(float angle);
      bool belongingPoint(const Point2f& point)const;
      bool shapeIntersection(const I_Shape& inputShape,
                             std::list<Point2f>* genPoint=NULL);
      
      float getDistance(const Point2f& pt, Point2f* close_pt=NULL)const;
      void getX(float y, std::vector<float>* x)const;
      void getY(float x, std::vector<float>* y)const;
      
      void toSegments();
      int  isSegmented();
      
      // --- data ---
      std::list<Reduced_vector> m_vec;
      std::list<Convex_contour> m_contours;
      int m_status;
   };

   Reduced_vector getBisector( const Reduced_vector& vect1,
                               const Reduced_vector& vect2 );
   
   Reduced_vector getBisector( const Reduced_vector& vect1,
                               const Reduced_vector& vect2,
                               float vect1_lenght,
                               float vect2_lenght );
   
   void getBorder( const std::list<Point2f>& points,
                   Point2f* minPt, Point2f* maxPt );

   void getVerticalBorderPoint(const std::list<Point2f>&points,
                               Point2f* pt_min, Point2f* pt_max);

   void getHorizontalBorderPoint(const std::list<Point2f>& points,
                                 Point2f* pt_min, Point2f* pt_max);

   void contourToConvexContour(Contour* cont);

   Contour pointsToConvex( const std::list<Point2f>& points,
                           const float sizeStep );

   float distance(const Point2f& pt1, const  Point2f& pt2);

   std::list<Point2f> getRandomPointCloud(int n,
                                          Point2f lowBorder,
                                          Point2f upBorder);

   const int SHAPE_NOT_INTERSECTION = 0;
   const int SHAPE_INTERSECTION     = 1;
   const int SHAPE_MATCH            = 2;
   //const int SHAPE_LINE_PARALLEL    = 3;

   // --- with dynamic cast ---
   int shapeIntersection(const I_Shape&,
                         const I_Shape&,
                         std::list<Point2f>* genPoinut=NULL);

   int shapeIntersection(const Circle&,
                         const I_Shape&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Line_2d&,
                         const I_Shape&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Interval&,
                         const I_Shape&,
                         std::list<Point2f>* genPoint=NULL);\

   int shapeIntersection(const Contour&,
                         const I_Shape&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Convex_contour&,
                         const I_Shape&,
                         std::list<Point2f>* genPoint=NULL);

   // --- without dynamic cast ---
   // --- if you can - use it and not with dynamic cast
   int shapeIntersection(const Circle&,
                         const Circle&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Line_2d&,
                         const Line_2d&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Interval&,
                         const Interval&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Contour&,
                         const Contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Convex_contour&,
                         const Convex_contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Circle&,
                         const Line_2d&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Circle&,
                         const Interval&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Circle&,
                         const Contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Circle&,
                         const Convex_contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Line_2d&,
                         const Interval&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Line_2d&,
                         const Contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Line_2d&,
                         const Convex_contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Interval&,
                         const Contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Interval&,
                         const Convex_contour&,
                         std::list<Point2f>* genPoint=NULL);

   int shapeIntersection(const Contour&,
                         const Convex_contour&,
                         std::list<Point2f>* genPoint=NULL);

   Point2f searchCenterCloud(const std::list< Point2i >& cloud);
   Point2f searchCenterCloud(const std::list< Point2f >& cloud);

   void minMaxPointCloud( const std::list< Point2i >& cloud,
                          Point2i* outMaxPoint,
                          Point2i* outMinPoint );

   void minMaxPointCloud( const std::list< Point2f >& cloud,
                          Point2f* outMaxPoint,
                          Point2f* outMinPoint );

   void uniq_point_copy( const std::list< Point2f >& cloud,
                                std::list< Point2f >* p_unic_cloud );

   void uniqPoint( std::list< Point2f >* cloud );
   
   void turnShape( I_Shape* shape, float angle, Point2f basePt);
   //void turnShape( I_Shape* src, I_Shape* dst, Point2f basePt);
   
   struct Geometry_error
   {
      Geometry_error(const char* _name):name(_name){};
      const char* name;
   };

}//end Geometry

#endif //GEOMETRY_H
