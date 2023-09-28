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

    // constructors
        Fixed();
        Fixed (const Fixed &copy);
        Fixed (const int val);
        Fixed (const float val);

    // compariason operator
        void operator=(const Fixed &src);
        bool operator > (const Fixed &src);
        bool operator < (const Fixed &src);
        bool operator >= (const Fixed &src);
        bool operator <= (const Fixed &src);
        bool operator == (const Fixed &src);
        bool operator != (const Fixed &src);

    // arithmethic operator

        Fixed operator + (const Fixed &src);
        Fixed operator - (const Fixed &src);
        Fixed operator * (const Fixed &src);
        Fixed operator / (const Fixed &src);

    // static member function
        static Fixed& min(Fixed &a,Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a,Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

    // post-increment && pre-increment operator function
        Fixed operator ++(int);
        Fixed operator ++();

    // getter and setter
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        ~Fixed();
    
};
std :: ostream& operator << (std :: ostream &out,const Fixed &src);
float eps();
#endif
