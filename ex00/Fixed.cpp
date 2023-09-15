#include "Fixed.hpp"

	Fixed::Fixed(void)
	{
		std::cout << "Default Constructor" << std::endl;
		this->fixedPoint = 0;
	}
	
	Fixed::Fixed(Fixed const & src)
	{
		std::cout << "Copy Constructor" << std::endl;
		*this = src;
		return ;
	}

	Fixed::~Fixed(void)
	{
		std::cout << "Destructor" << std::endl;
	}

	int	Fixed::getRawBits(void) const
	{
		std::cout << "getRawBits called" << std::endl;
		return (this->fixedPoint);
	}

	void	Fixed::setRawBits(int const raw)
	{
		std::cout << "setRawBits called" << std::endl;
		this->fixedPoint = raw;
	}

	Fixed &	Fixed::operator=(Fixed const & rhs)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->fixedPoint = rhs.getRawBits();
		return (*this);
	}