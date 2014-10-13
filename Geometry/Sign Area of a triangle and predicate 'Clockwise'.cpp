/*
Name: Computing the area of a triangle with the coordinates of the three points.
Division: Geometry
*/

/* The result of the function is twice the area of the triangle.
   If if is zero, then the points are in a line.
   If it is positive then the inputted points are in counter-clockwise manner.
   If it is negative then the inputted points are in clockwise manner.

   The details is described here:
   https://drive.google.com/file/d/0Bx_k4W7iySbtQ0lBR21sbkdKbmc/view?pli=1
*/

int triangle_area( int x1, int y1, int x2, int y2, int x3, int y3 ) {
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
}
