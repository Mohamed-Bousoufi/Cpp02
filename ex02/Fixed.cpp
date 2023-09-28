#include "Fixed.hpp"

Fixed :: Fixed()
{
    this->value = 0;
    std :: cout << "Default constructor called" << std :: endl;
}

Fixed :: Fixed( const Fixed &copy)
{
    std :: cout << "copy constructor called" << std :: endl;
    *this = copy;
}

Fixed :: Fixed(const int val)
{
    int scale;

    scale = 1 << this->fractbits;

    this->value = val * scale;
    std :: cout << "Int constructor called" << std :: endl;

}

Fixed :: Fixed(const float val)
{
    int scale;

    scale = 1 << this->fractbits;

    this->value = roundf(val * scale);
    std :: cout << "Float constructor called" << std :: endl;
}

Fixed :: ~Fixed()
{
    std :: cout << "Destructor called" << std :: endl;
}

int Fixed :: getRawBits(void) const
{
    return(this->value);
}

void Fixed :: operator=( const Fixed &src)
{

    std :: cout << "Copy assignment operator called" << std :: endl;
    this->value = src.getRawBits();
}

bool  Fixed :: operator> (const Fixed & src)
{
    if(this->value > src.value)
    {
        return true;
    }
    else
        return false;
}

bool Fixed :: operator < (const Fixed & src)
{
    if(this->value < src.value)
    {
        return true;
    }
    else
        return false;
}

bool Fixed :: operator>= (const Fixed & src)
{
    if(this->value >= src.value)
    {
        return true;
    }
    else
        return false;
}

bool Fixed :: operator <= (const Fixed & src)
{
    if(this->value <= src.value)
    {
        return true;
    }
    else
        return false;
}

bool Fixed :: operator == (const Fixed & src)
{
    if(this->value == src.value)
    {
        return true;
    }
    else
        return false;
}

bool Fixed :: operator != (const Fixed & src)
{
    if(this->value != src.value)
    {
        return true;
    }
    else
        return false;
}

Fixed Fixed :: operator + (const Fixed &src)
{

   return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed :: operator - (const Fixed &src)
{
   return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed :: operator * (const Fixed &src)
{
   return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed :: operator / (const Fixed &src)
{
    if(src.value != 0)
        return Fixed(this->toFloat() / src.toFloat());
    else
    {
        std :: cout << "division by 0 it is Unacceptable" << std :: endl;
        return(0);
    }
}

//  post-increment
Fixed Fixed :: operator++(int)
{
    Fixed comp(*this);
    this->value++;
    return(comp);
}

// (pre-increment)
Fixed Fixed :: operator++()
{
    this->value++;

    return(*this);
}

Fixed& Fixed :: min(Fixed &a,Fixed &b)
{
    if(a <= b)
        return(a);
    else
        return(b);
}

const Fixed &Fixed :: min(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() <= b.getRawBits())
        return(a);
    else
        return(b);
}

Fixed& Fixed :: max(Fixed &a,Fixed &b)
{
    if(a >= b)
        return(a);
    else
        return(b);
}

const Fixed &Fixed :: max(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() >= b.getRawBits())
        return(a);
    else
        return(b);
}




float Fixed :: toFloat( void ) const
{
    float res;
    float scale;

    scale = 1 << fractbits;
    res = this->value / scale;
    return(res);
}

int Fixed :: toInt( void ) const
{
    int res;
    int scale;

    scale = 1 << fractbits;
    res = this->value / scale;
    return(res);
}



void Fixed :: setRawBits( int const raw )
{
    this->value = raw;
}

std :: ostream& operator << (std :: ostream &out,const Fixed &src)
{
    out << src.toFloat();
    return(out);
}
