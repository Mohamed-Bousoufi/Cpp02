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

bool Fixed :: operator> (const Fixed & src)
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