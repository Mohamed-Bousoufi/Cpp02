#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>
#include<cmath>

class Fixed
{
    private :
        int value;
        static const int fractbits = 8;
    public :
        Fixed();
        Fixed (const Fixed &copy);
        Fixed (const int val);
        Fixed (const float val);
        void operator=(const Fixed &src);
        bool operator > (const Fixed &src);
        bool operator < (const Fixed &src);
        bool operator >= (const Fixed &src);
        bool operator <= (const Fixed &src);
        bool operator == (const Fixed &src);
        bool operator != (const Fixed &src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;


        ~Fixed();
    
};
std :: ostream& operator << (std :: ostream &out,const Fixed &src);
#endif
