#include "Fixed.hpp"

int	main(void)
{
	
	{
		Fixed n1(4);
		Fixed	n2(1.5f);
		Fixed	n4(2.5f);
		Fixed	n3 = n1 + n2 + n4;
		std::cout << "n3 resultante de suma: " << n3 << std::endl;
		std::cout << "n3 int: " << n3.toInt() << std::endl;
		std::cout << "n3 float: " << n3.toFloat() << std::endl;
		n3 = n2 - n1;
		std::cout << "n3 resultante de resta: " << n3 << std::endl;
		std::cout << "n3 int: " << n3.toInt() << std::endl;
		std::cout << "n3 float: " << n3.toFloat() << std::endl;
		n3 = n1 * n2 * n4;
		std::cout << "n3 resultante de multiplicación: " << n3 << std::endl;
		std::cout << "n3 int: " << n3.toInt() << std::endl;
		std::cout << "n3 float: " << n3.toFloat() << std::endl;
		n3 = n1 / n4;
		std::cout << "n3 resultante de división: " << n3 << std::endl;
		std::cout << "n3 int: " << n3.toInt() << std::endl;
		std::cout << "n3 float: " << n3.toFloat() << std::endl;
	}
	{
		Fixed 	n1(1.5f);
		Fixed	n2(1.6f);

		std::cout << "n2: " << n2 << std::endl;
		std::cout << "n1: " << n1 << std::endl;
		
		if (n1 > n2)
			std::cout << "n1 mayor a n2" << std::endl;
		if (n1 < n2)
			std::cout << "n1 menor a n2" << std::endl;
		if (n1 >= n2)
			std::cout << "n1 mayor o igual a n2" << std::endl;
		if (n1 <= n2)
			std::cout << "n1 menor o igual a n2" << std::endl;
		if (n1 == n2)
			std::cout << "n1 igual a n2" << std::endl;
		if (n1 != n2)
			std::cout << "n1 distinto a n2" << std::endl;
		std::cout << "Post-incremento de n1" << std::endl;
		n1++;
		std::cout << "n1: " << n1 << std::endl;
		std::cout << "Pre-incremento de n1 y asignación a n2" << std::endl;
		n2 = ++n1;
		std::cout << "n2: " << n2 << std::endl;
		std::cout << "n1: " << n2 << std::endl;
		std::cout << "Post-incremento de n1 y asignación a n2" << std::endl;
		n2 = n1++;
		std::cout << "n2: " << n2 << std::endl;
		std::cout << "n1: " << n1 << std::endl;
		std::cout << "Menor de n1 y n2: " << n1.min(n1, n2) << std::endl;
		std::cout << "Mayor de n1 y n2: " << n1.max(n1, n2) << std::endl;
	}
	return (0);
}