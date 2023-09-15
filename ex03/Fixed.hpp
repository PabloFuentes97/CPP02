#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedPoint;
		int static const	bitsFrac = 8;
	public:
		Fixed(void);
		Fixed(int num);
		Fixed(float num);
		Fixed(Fixed const & src);
		~Fixed(void);
		float	toFloat(void) const;
		int		toInt(void)	const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed &	operator=(Fixed const & rhs); 
		bool	operator>(Fixed const &cmp) const;
		bool	operator<(Fixed const &cmp) const;
		bool	operator>=(Fixed const &cmp) const;
		bool	operator<=(Fixed const &cmp) const;
		bool	operator==(Fixed const &cmp) const;
		bool	operator!=(Fixed const &cmp) const;
		Fixed & operator++();
		Fixed	operator++(int);
		Fixed & operator--();
		Fixed	operator--(int);
		static Fixed & min(Fixed &num1, Fixed &num2);
		static const Fixed & min(Fixed const &num1, Fixed const &num2);
		static Fixed & max(Fixed &num1, Fixed &num2);
		static const Fixed & max(Fixed const &num1, Fixed const &num2);
};

Fixed	operator+(Fixed const &num1, Fixed const &num2);
Fixed	operator-(Fixed const &num1, Fixed const &num2);
Fixed 	operator*(Fixed const &num1, Fixed const &num2);
Fixed 	operator/(Fixed const &num1, Fixed const &num2);
std::ostream &operator<<(std::ostream & o, Fixed const & rhs);