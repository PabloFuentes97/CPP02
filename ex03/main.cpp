#include "Point.hpp"

int	main(void)
{
	Point	p = Point(4, 5);
	Point	a = Point(3, 2);
	Point	b = Point(5, 2);
	Point	c = Point(4, 8);

	if (bsp(a, b, c, p))
		std::cout << "Punto está dentro" << std::endl;
	else
		std::cout << "Punto está fuera" << std::endl;
	return (0);
}