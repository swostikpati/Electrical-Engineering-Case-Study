//Importing dependencies
#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

//Point class implementation
//Default Constructor of Point
Point :: Point()
{
    x = 0.0;
    y = 0.0;
}

//Non-default Constructor of Point
Point :: Point(double a, double b)
{
    x = a;
    y = b;
}

//Getters and Setters
double Point::getX()
{
    return x;
}
double Point ::getY()
{
    return y;
}
void Point ::setX(double z1)
{
    x = z1;
}
void Point ::setY(double z2)
{
    y = z2;
}
//Function to print point info
void Point ::printPointInfo()
{
    cout << x << "," << y << endl;
}