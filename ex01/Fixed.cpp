#include "Fixed.hpp"

	Fixed::Fixed(void)
	{
		//std::cout << "Default Constructor" << std::endl;
		this->fixedPoint = 0;
	}
	
	Fixed::Fixed(int num)
	{
		//std::cout << "Constructor with int arg" << std::endl;
		this->fixedPoint = (int)roundf(num * (1 << this->bitsFrac));
		//std::cout << this->fixedPoint << std::endl;
	}

	Fixed::Fixed(float num)
	{
		//std::cout << "Constructor with float arg" << std::endl;
		this->fixedPoint = (int)roundf(num * (1 << this->bitsFrac));
		//std::cout << this->fixedPoint << std::endl;
	}
	int		Fixed::toInt(void)  const
	{
		return ((int)this->fixedPoint / (int)(1 << this->bitsFrac));
	}

	float	Fixed::toFloat(void) const
	{
		return ((float)this->fixedPoint / (float)(1 << this->bitsFrac));
	}

	Fixed::Fixed(Fixed const & src)
	{
		//std::cout << "Copy Constructor" << std::endl;
		*this = src;
		return ;
	}

	Fixed::~Fixed(void)
	{
		//std::cout << "Destructor" << std::endl;
	}

	int	Fixed::getRawBits(void) const
	{
		//std::cout << "getRawBits called" << std::endl;
		return (this->fixedPoint);
	}

	void	Fixed::setRawBits(int const raw)
	{
		//std::cout << "setRawBits called" << std::endl;
		this->fixedPoint = raw;
	}

	float	Fixed::getFractionPart(void) const
	{
		int	fracPartRaw = this->fixedPoint & this->fractionMask;

		//std::cout << "Fractional part in raw bits: " << fracPartRaw << std::endl;
		return ((float)fracPartRaw / (float)(1 << this->bitsFrac));
	}

	int		Fixed::getWholePart(void) const
	{
		int	wholePartRaw = this->fixedPoint & this->wholeMask;
	
		//std::cout << "Whole part in raw bits: " << wholePartRaw << std::endl;
		return (((int)wholePartRaw / (int)(1 << this->bitsFrac)));
	}

	Fixed &	Fixed::operator=(Fixed const & rhs)
	{
		//std::cout << "Assignation operator called" << std::endl;
		this->fixedPoint = rhs.getRawBits();
		return (*this);
	}

	std::ostream &operator<<(std::ostream & o, Fixed const & rhs)
	{
		//std::cout << "Operator << overload" << std::endl;
		o << rhs.toFloat();
		return (o);
	}