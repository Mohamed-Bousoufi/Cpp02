#include "Point.hpp"

float area (Point   &a,Point  &b,Point &c)
{
   float Area;
   float ax = a.GetPointx();
   float ay = a.GetPointy();
   float bx = b.GetPointx();
   float by = b.GetPointy();
   float cx = c.GetPointx();
   float cy = c.GetPointy();

   Area = (0.5) * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));

   if(Area < 0)
      Area *= -1;
   return(Area);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
   float marea;
   float larea;
   float rarea;
   float darea;

   marea = area(const_cast<Point &>(a),const_cast<Point &>(b),const_cast<Point &>(c));
   larea = area(const_cast<Point &>(a),const_cast<Point &>(point),const_cast<Point &>(b));
   rarea = area(const_cast<Point &>(a),const_cast<Point &>(point),const_cast<Point &>(c));
   darea = area(const_cast<Point &>(point),const_cast<Point &>(b),const_cast<Point &>(c));

   if((marea == larea + rarea + darea) && marea != 0 && larea != 0 && rarea != 0 && darea != 0)
         return(true);
   else 
      return(false);
}