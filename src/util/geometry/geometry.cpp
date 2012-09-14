/**
 ** autor   Alexander K
 ** date    24.06.2012.12.35
 ** BRIEF   GEOMETRY UTIL
*/

//=============================================================================
//#include <iostream>
//#include <iterator>
//#include <cmath>
//=============================================================================
//#include "include/geometry.h"
//#include "include/math.h"
//=============================================================================
/*float Geometry::distanse(Geometry::Point2f& pt1, Geometry::Point2f& pt2)
{
	return std::sqrt((pt1.x-pt2.x)*(pt1.x-pt2.x)+(pt1.y-pt2.y)*(pt1.y-pt2.y));
}
Geometry::Point2i::Point2i(int _x, int _y)
	 : x(_x),
		y(_y)
{}

Geometry::Point2f::Point2f(float _x, float _y)
	 : x(_x),
		y(_y)
{}

Geometry::Circle::Circle(Geometry::Point2f& center, float radius)
	 : m_center(center),
		m_radius(radius)
{}

Geometry::Circle::Circle(Geometry::Point2f& center, Geometry::Point2f& circlePoint)
	: m_center(center)
{
	m_radius = distanse(center, circlePoint);
}
Geometry::Circle::Circle(Geometry::Point2f& pt1,
								 Geometry::Point2f& pt2,
								 Geometry::Point2f& pt3)
{
	std::cout << "realisation not compleet!\n"
}

void Geometry::Circle::create(Geometry::Point2f& center, float radius)
{
	m_center = center;
	m_radius = radius;
}
void Geometry::Circle::create(Geometry::Point2f center, Geometry::Point2f circlePoint)
{
	m_radius = distanse(center, circlePoint);
	m_center = center;
}
//void create(Point2f pt1, Point2f pt2, Point2f pt3);

bool Geometry::Circle::belongingPoint(Geometry::Point2f& point)
{
	float realRad =
			(m_center.x-point.x)*(m_center.x-point.x)
				+(m_center.y-point.y)*(m_center.y-point.y);
	return Math::equal(realRad, m_radius);
}
bool Geometry::Circle::insidePoint(Geometry::Point2f& point)
{
	return m_radius < Geometry::distanse(m_center, point);
}
bool Geometry::Circle::shapeIntersection(Geometry::I_Shape& inputShape)
{

}

//	class 2D_line : public I_Shape
Geometry::2d_line::2D_line(Geometry::Point2f pt1, Geometry::Point2f pt2)
{}
void Geometry::2d_line::turn(float angle)
{

}

bool Geometry::2d_line::belongingPoint(Geometry::Point2f& point)
{}
bool Geometry::2d_line::shapeIntersection(Geometry::I_Shape& inputShape)
{}


//	class Rectangle : public I_Shape
Geomtry::Rectangle::Rectangle(Geometry::Pointaf pt, float width, float height)
{}

void Geometry::Rectangle::turn(float angle)
{}
bool Geometry::Rectangle::belongingPoint(Geometry::Point2f& point)
{}
bool Geometry::Rectangle::shapeIntersection(Geometry::I_Shape& inputShape)
{}

//	class Triangle : public I_Shape
Geometry::Triangle::Triangle(pt1, pt2, pt3)
{}

void Geometry::Triangle::turn(float angle)
{}
bool Geometry::Triangle::belongingPoint(Geometry::Point2f& point)
{}
bool Geometry::Triangle::shapeIntersection(Geometry::I_Shape& inputShape)
{}
bool Geometry::shapeIntersection(Geometry::2d_line& line,
								Geometry::Circle& circ,
								std::list<Geometry::Point2f>* genPoint)
{
	vector CK - perpendicular for line
		C is center od cicle
}

bool Geometry::shapeIntersection(Geometry::Circle& circ1,
								Geometry::Circle& circ2,
								std::vector<Geometry::Point2f>* genPoins)
{
	//if center1 are inside circle2
	if ( circ2.insidePoint(circ1.getCenter()) )
	{
		float c1c2 = Geometry::distanse(circ1.getCenter(),circ2.getCenter());
		if ( c1c2 + circ2.getRadius() < circ1.getRadius())
			return false;
	}

	if ( circ1.insidePoint(circ2.getCenter()) )
	{
		float c1c2 = Geometry::distanse(circ1.getCenter(),circ2.getCenter());
		if ( c1c2 + circ1.getRadius() < circ2.getRadius())
			return false;
	}

	if ( equal(circ1.getRadius(), circ2.getRadius())
			&& equal(circ1.getCenter().x, circ2.getCenter().x)
			&& equal(circ1.getCenter().y, circ2.getCenter().y) )
	{
		Geometry::Point2f centerPoint(circ1.getCenter());
		std::vector<float> xs;
		std::vector<float> xs;
		circ1.getX(centerPoint.y, xs);
		circ1.getY(centerPoint.x, ys);

		genPoints->push_back(Geometry::point2f(xs[0], centerPoint.y));
		genPoints->push_back(Geometry::point2f(xs[1], centerPoint.y));
		genPoints->push_back(Geometry::point2f(centerPoint.x, ys[0]));
		genPoints->push_back(Geometry::point2f(centerPoint.x, ys[1]));
		return true;
	}
}
*/
