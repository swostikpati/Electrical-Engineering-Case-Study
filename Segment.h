#ifndef Segment_hpp
#define Segment_hpp

#include <stdio.h>
#include "Point.h"


using namespace std;

//Class Segment defination
class Segment{
    private:
    Point start;
    Point end;
    double angle;
    double length;
    double sum_angle;

    public:
    Segment();

    Segment(double a, double l);
   
    Segment(Point s, double a, double l, double S);

    Point getStart();
    
    void setStart(Point y);
    
    Point getEnd();
   
    double getAngle();
    
    void setAngle(double z);
   
    double getLength();

    void setLength(double d);
   
    double getSumAngle();

    Segment createChild(double a, double l);

    Point findEndPoint(Point S, double sum_a, double l);

    void printSegmentInfo();

};
#endif