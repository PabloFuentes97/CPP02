#include "Fixed.hpp"

	Fixed::Fixed(void)
	{
		//std::cout << "Default Constructor" << std::endl;
		this->fixedPoint = 0;
	}
	
	Fixed::Fixed(int num)
	{
		//std::cout << "Constructor with int arg" << std::endl;
		this->fixedPoint = (int)roundf(num * (int)(1 << this->bitsFrac));
		//std::cout << this->fixedPoint << std::endl;
	}

	Fixed::Fixed(float num)
	{
		//std::cout << "Constructor with float arg" << std::endl;
		this->fixedPoint = (int)roundf(num * (float)(1 << this->bitsFrac));
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

	Fixed operator+(Fixed const &num1, Fixed const &num2)
	{
		Fixed sum;

		sum.setRawBits(num1.getRawBits() + num2.getRawBits());
		return (sum);
	}

	Fixed operator-(Fixed const &num1, Fixed const &num2)
	{
		Fixed rest;

		rest.setRawBits(num1.getRawBits() - num2.getRawBits());
		return (rest);
	}

	Fixed operator*(Fixed const &num1, Fixed const &num2)
	{
		Fixed mult;

		//mult.setRawBits((num1.getRawBits() >> 8) * (num2.getRawBits() >> 8) >> 0); //less precision and range
		mult.setRawBits(((long int)num1.getRawBits() * (long int)num2.getRawBits()) >> 8); //slower
		return (mult);
	}

	Fixed operator/(Fixed const &num1, Fixed const &num2)
	{
		Fixed div;

		//div.setRawBits((num1.getRawBits() << 8) / (num2.getRawBits() << 8) >> 0); //less precision and range
		div.setRawBits(((long int)num1.getRawBits() << 8) / (long int)num2.getRawBits()); //slower
		return (div);
	}

	bool	Fixed::operator>(Fixed const &cmp) const 
	{
		return (this->getRawBits() > cmp.getRawBits());
	}

	bool	Fixed::operator<(Fixed const &cmp) const
	{
		return (this->getRawBits() < cmp.getRawBits());
	}

	bool	Fixed::operator>=(Fixed const &cmp) const
	{
		return (this->getRawBits() >= cmp.getRawBits());
	}

	bool	Fixed::operator<=(Fixed const &cmp) const
	{
		return (this->getRawBits() <= cmp.getRawBits());
	}

	bool	Fixed::operator==(Fixed const &cmp) const
	{
		return (this->getRawBits() == cmp.getRawBits());
	}

	bool	Fixed::operator!=(Fixed const &cmp) const
	{
		return (this->getRawBits() != cmp.getRawBits());
	}

	Fixed & Fixed::operator++()
	{
		this->setRawBits(this->getRawBits() + 1);
		return (*this);
	}
	Fixed	Fixed::operator++(int)
	{
		Fixed	copy = *this;
		this->setRawBits(this->getRawBits() + 1);
		return (copy);
	}

	Fixed & Fixed::operator--()
	{
		this->setRawBits(this->getRawBits() - 1);
		return (*this);
	}
	Fixed	Fixed::operator--(int)
	{
		Fixed	copy = *this;
		this->setRawBits(this->getRawBits() - 1);
		return (copy);
	}

	Fixed & Fixed::min(Fixed &num1, Fixed &num2)
	{
		if (num1 < num2)
			return (num1);
		return (num2);
	}
	
	const Fixed & Fixed::min(Fixed const &num1, Fixed const &num2)
	{
		if (num1 < num2)
			return (num1);
		return (num2);
	}
	
	Fixed & Fixed::max(Fixed &num1, Fixed &num2)
	{
		if (num1 > num2)
			return (num1);
		return (num2);
	}
	
	const Fixed & Fixed::max(Fixed const &num1, Fixed const &num2)
	{
		if (num1 > num2)
			return (num1);
		return (num2);
	}

	std::ostream &operator<<(std::ostream & o, Fixed const & rhs)
	{
		//std::cout << "Operator << overload" << std::endl;
		o << rhs.toFloat();
		return (o);
	}