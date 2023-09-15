#include "Fixed.hpp"

int	main(void)
{
	{
		int	bits = 1 << 8;
		std::cout << "1 desplazado 8 bits a la izquierda: " << bits << std::endl;
		std::cout << "3 por bits desplazados: " << 3 * bits << std::endl;
		std::cout.precision(15);
		Fixed a;
		Fixed b(3);
		Fixed c;
		c = b;
		Fixed d(12.44f);
		std::cout << "A: " << a.getRawBits() << std::endl;
		std::cout << "B: " << b.getRawBits() << std::endl;
		std::cout << "C: " << c.getRawBits() << std::endl;
		std::cout << "B: " << b.toInt() << std::endl;
		std::cout << "B: " << b.toFloat() << std::endl;
		std::cout << "C: " << b.toInt() << std::endl;
		std::cout << "C: " << b.toFloat() << std::endl;
		std::cout << "D: " << d.toInt() << std::endl;
		std::cout << "D: " << d.toFloat() << std::endl;
		std::cout << "D en float: " << 12.44f << std::endl;
		std::cout << "D: " << d << std::endl;
		std::cout << "B: " << b << std::endl;
		std::cout << "D fracPart converted: " << d.getFractionPart() << std::endl;
		std::cout << "D wholePart converted: " << d.getWholePart() << std::endl;
	}
	{
		std::cout << "\n\n\nMain subject\n\n\n" << std::endl;
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	return 0;
}