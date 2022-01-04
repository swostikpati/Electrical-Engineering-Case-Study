//Importing headers and dependencies
#include "Segment.h"
#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

//Segment class implementation
//Default Constructor
Segment :: Segment()
{
    angle = 0.0;
    length = 0.0;
}

//Non-default constructor for root segment
Segment :: Segment(double a, double l)
{ 
    sum_angle = a;
    angle = a;
    length = l;
    end = findEndPoint(start, sum_angle, l);
}

//Non-default constructor for other segments
Segment :: Segment(Point s, double a, double l, double S)
{
    //a1 and l1 are the parameters of the previous segment
    sum_angle = S + a;

    start = s;
    angle = a;
    length = l;
    end = findEndPoint(start, sum_angle, l);
}

//Getters and Setters
Point Segment ::getStart()
{
    return start;
}
void Segment ::setStart(Point y)
{
    start = y;
}

Point Segment::getEnd()
{
    return end;
}
double Segment::getAngle()
{
    return angle;
}
void Segment::setAngle(double z)
{
    angle = z;
}
double Segment ::getLength()
{
    return length;
}
void Segment ::setLength(double d)
{
    length = d;
}
double Segment ::getSumAngle()
{
    return sum_angle;
}

//Creates child segments
Segment Segment ::createChild(double a, double l)
{
    Segment child(end, a, l, sum_angle);
    return child;
}

//Finds end point
Point Segment::findEndPoint(Point S, double sum_a, double l)
{
    //formula to calculate end point
    end.setX(S.getX() + (l * cos(sum_a)));
    end.setY(S.getY() + (l * sin(sum_a)));
    return end;
}

//Print segment info
void Segment ::printSegmentInfo()
{
    cout << "The segment starts at: ";
    start.printPointInfo();
    cout << endl;
    cout << "The segment ends at: ";
    end.printPointInfo();
    cout << endl;
    cout << "The length of the segment is " << length << endl;
    cout << "The angle of the segment is " << angle << endl;
}