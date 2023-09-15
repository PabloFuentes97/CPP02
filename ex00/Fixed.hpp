#include <iostream>

class Fixed
{
	private:
		int	fixedPoint;
		int static const	bitsFrac = 8;
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed &	operator=(Fixed const & rhs);
};