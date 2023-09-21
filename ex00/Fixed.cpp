#include "Fixed.hpp"

Fixed :: Fixed()
{
    this->value = 0;
    std :: cout << "Default constructor called" << std :: endl;
}

Fixed :: Fixed(Fixed &copy)
{
    this->value = copy.value;
    std :: cout << "copy constructor called" << std :: endl;
}
Fixed :: ~Fixed()
{
     std :: cout << "Default Destructor called" << std :: endl;
}

int Fixed :: getRawBits(void) const
{
    std :: cout << "getRawBits member function called" << std :: endl;
    return(this->value);
}

void  Fixed :: operator=(Fixed &src)
{
    std :: cout << "Copy assignment operator called" << std :: endl;
    this->value = src.getRawBits();
}
void Fixed :: setRawBits( int const raw )
{
    this->value = raw;
}
