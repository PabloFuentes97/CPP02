#include "Fixed.hpp"

int	main(void)
{
	
	{
		Fixed n1(4);
		Fixed	n2(1.5f);
		Fixed	n4(2.5f);
		Fixed	n3 = n1 + n2 + n4;
		std::cout << n3 << std::endl;
		std::cout << n3.toInt() << std::endl;
		n3 = n2 - n1;
		std::cout << n3 << std::endl;
		std::cout << n3.toInt() << std::endl;
		n3 = n1 * n2 * n4;
		std::cout << "MULTIPLICACIÓN" << std::endl;
		std::cout << n3 << std::endl;
		std::cout << n3.toInt() << std::endl;
		n3 = n1 / n4;
		std::cout << "DIVISIÓN" << std::endl;
		std::cout << n3 << std::endl;
		std::cout << n3.toFloat() << std::endl;
		std::cout << n3.toInt() << std::endl;
	}
	{
		Fixed n1(1.5f);
		Fixed	n2(1.6f);

		if (n1 != n2)
			std::cout << "n1 distinto a n2" << std::endl;
		n1++;
		std::cout << n1 << std::endl;
		n2 = ++n1;
		std::cout << n2 << std::endl;
		n2 = n1++;
		std::cout << n2 << std::endl;
		std::cout << n1 << std::endl;
	}
	return (0);
}