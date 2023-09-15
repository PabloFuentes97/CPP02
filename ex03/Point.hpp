#include "Fixed.hpp"

#define X 0
#define Y 1
class	Point{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point(void);
		Point(float x, float y);
		Point(Point const & src);
		~Point(void);
		const Fixed & getFixed(int index) const;
		Point	operator=(Point const & rhs);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);