#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>
#include "Point.h"
#include "Segment.h"
using namespace std;

//Defining Robot class
class Robot
{
private:
    Segment root;
    Point endEffector;
    int num;

public:
    Robot();

    Robot(Segment r);

    Point getEndEff();

    Segment getRoot();

    void addSegment(Segment x);

    void delSegment(Segment arr[], int n);
    void printRobotInfo();
    void forwardK(double ang[], Segment arr[], int n);
    void reset(Segment arr[], int n);
    void graphPose(double arr_x[], double arr_y[], int n);
    void getGraph();
};

#endif