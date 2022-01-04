#ifndef Point_h
#define Point_h

#include <stdio.h>

using namespace std;

//Class Point defination
class Point
{

private:
    double x;
    double y;

public:
    Point();

    Point(double a, double b);

    double getX();

    double getY();

    void setX(double z1);

    void setY(double z2);

    void printPointInfo();
};

#endif