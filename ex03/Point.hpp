#ifndef POINT_H
#define POINT_H


#include "Fixed.hpp"

class Point 
{
    private :
            const Fixed x;
            const Fixed y;
    public :
    // constructor 
                Point();
                Point(const float x,const float y);
                Point(Point &src);
                void operator =(Point &src);
                ~Point();
    // getter setter
        void SetPointy(float y);
        void SetPointx(float x);

        float GetPointy();
        float GetPointx();
};
float area(Point &a,Point &b,Point &c);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif