#include "Point.hpp"


// const_cast is used to cast away the constness of variables.

Point :: Point()
{
   std :: cout << "default constructor called" << std :: endl;
   Fixed px(0);
   Fixed py(0);
   const_cast<Fixed &>(this->x) = px;
   const_cast<Fixed &>(this->y) = py;
}

Point :: Point(const float x,const float y)
{
   std :: cout << "paramitized constructor called " << std :: endl;
   Fixed px(x);
   Fixed py(y);
   const_cast<Fixed &>(this->x) = px;
   const_cast<Fixed &>(this->y) = py;
}

Point :: Point(Point &src)
{  
   (const_cast<Fixed &>(this->x)) = src.x;
   (const_cast<Fixed &>(this->y)) = src.y;
   std :: cout << "copy constructor called " << std :: endl;
}

void Point :: operator=(Point &src)
{
   (const_cast<Fixed &>(this->x)) = src.x;
   (const_cast<Fixed &>(this->y)) = src.y;
   std :: cout << "Copy assignment operator called " << std :: endl;

}
Point :: ~Point()
{
   std :: cout << "Destructor called" << std :: endl;
}

float Point :: GetPointx()
{
   return(this->x.toFloat());
}

float Point :: GetPointy()
{
   return(this->y.toFloat());
}
