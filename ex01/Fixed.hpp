#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedPoint;
		int static const	bitsFrac = 8;
		int	static const	fractionMask = 0xffffffff >> (32 - bitsFrac);
		int	static const	wholeMask = -1 ^ fractionMask;
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
		float	getFractionPart(void) const;
		int		getWholePart(void) const;
		Fixed &	operator=(Fixed const & rhs);
		
};

std::ostream &operator<<(std::ostream & o, Fixed const & rhs);