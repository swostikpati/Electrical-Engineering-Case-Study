//Importing Dependencies and Headers
#include <iostream>
#include "Robot.h"
#include <vector>
#include "pbPlots.cpp"
#include "supportLib.cpp"

using namespace std;

//Robot class implementation
//Default constructor - creates robot with 0 segments
Robot ::Robot()
{

    num = 0;
    endEffector.setX(0);
    endEffector.setY(0);
}
//Non-default constructor - creates robot with 1 segment
Robot ::Robot(Segment r)
{
    num = 1;
    root = r;
    endEffector = root.getEnd();
}
//Returns end effector
Point Robot ::getEndEff()
{
    return endEffector;
}
//Returns root segment
Segment Robot ::getRoot()
{
    return root;
}
//Adds segment to robot
void Robot ::addSegment(Segment x)
{
    num++;
    endEffector = x.getEnd();
}
//Deletes segment from robot
void Robot ::delSegment(Segment arr[], int n)
{
    num--;
    endEffector = arr[n - 1].getStart();
}
//Prints robot info
void Robot ::printRobotInfo()
{
    cout << "Robot Details" << endl;
    cout << "Number of segments in the robot: " << num << endl;
    cout << "The end effector of the robot: ";
    endEffector.printPointInfo();
    cout << endl;
}
//Function for forward kinematics
void Robot ::forwardK(double ang[], Segment arr[], int n)
{
    double arr_x[n];
    double arr_y[n];
    arr_x[0] = 0;
    arr_y[0] = 0;
    double new_sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        new_sum += ang[i];
        arr[i].setAngle(ang[i]);
        this->endEffector = arr[i].findEndPoint(arr[i].getStart(), new_sum, arr[i].getLength());
        arr[i + 1].setStart(endEffector);
        if (i == 0)
        {
            continue;
        }
        else
        {
            arr_x[i] = endEffector.getX();
            arr_y[i] = endEffector.getY();
        }
    }
    //generates pose of the robot graph
    graphPose(arr_x, arr_y, n);
}
//Resets robot to standard configuration
void Robot ::reset(Segment arr[], int n)
{
    double zero[n];
    for (int i = 0; i < n; i++)
    {
        zero[i] = 0;
    }
    forwardK(zero, arr, n);
}
//Function to plot the pose of the robot in a graph and saves it
void Robot ::graphPose(double arr_x[], double arr_y[], int n)
{
    vector<double> x(arr_x, arr_x + n);
    vector<double> y(arr_y, arr_y + n);

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    DrawScatterPlot(imageRef, 800, 700, &x, &y);

    vector<double> *pngData = ConvertToPNG(imageRef->image);

    WriteToFile(pngData, "doraemon.png");

    DeleteImage(imageRef->image);
}
//Function to open the graph
void Robot ::getGraph()
{
    system("open doraemon.png");
}