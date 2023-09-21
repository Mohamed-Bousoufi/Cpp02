#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>

class Fixed
{
    private :
        int value;
        static const int fractbits = 8;
    public :
        Fixed();
        Fixed(Fixed &copy);
        void operator=(Fixed &src);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    
};
#endif
