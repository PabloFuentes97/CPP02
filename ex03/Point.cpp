#include "Point.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0))
{
	//std::cout << "Point Constructor" << std::endl;
	//this->x = Fixed(0);
	//this->y = Fixed(0);
}
Point::Point(float x1, float y1) : x(Fixed(x1)), y(Fixed(y1))
{
	//std::cout << "Point Constructor with parameters" << std::endl;
	//this->x = Fixed(x);
	//this->y = Fixed(y);
}
Point::Point(Point const & src) : x(Fixed(src.x)), y(Fixed(src.y))
{
	//std::cout << "Point Copy Constructor" << std::endl;
	//*this = src;
}
Point::~Point(void)
{
	//std::cout << "Point Destructor" << std::endl;
}
Point	Point::operator=(Point const & rhs)
{
	//std::cout << "Point Assignation operator called" << std::endl;
	const_cast<Fixed &>(this->x) = Fixed(rhs.x);
	const_cast<Fixed &>(this->y) = Fixed(rhs.y);
	return (*this);
}

const Fixed	& Point::getFixed(int index) const
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

float	calculateArea(const Point &a, const Point &b, const Point &c)
{
	Fixed	area;

	area = (a.getFixed(X)) * (b.getFixed(Y) - c.getFixed(Y)) 
	+ b.getFixed(X) * (c.getFixed(Y) - a.getFixed(Y)) 
	+ c.getFixed(X) * (a.getFixed(Y) - b.getFixed(Y));

	return (std::abs(area.toFloat() / 2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area;
	float	area1;
	float	area2;
	float	area3;

	area = calculateArea(a, b, c);
	area1 = calculateArea(a, b, point); // PAB
	area2 = calculateArea(a, c, point); // PAC
	area3 = calculateArea(b, c, point); // PBC
	if (area == 0 || area3 == 0 || area2 == 0 || area1 == 0) //comprobar si punto está dentro de un segmento
		return (false);
	return (area == area1 + area2 + area3);
}