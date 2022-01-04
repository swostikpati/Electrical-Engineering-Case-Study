//Importing Dependencies
#include <iostream>
#include <cmath>
#include <vector>
//Importing header files
#include "Point.cpp"
#include "Segment.cpp"
#include "Robot.cpp"

using namespace std;

//Function to input angles
void theta(double angles[], int n)
{
    cout << "Enter the angles: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> angles[i];
    }
}

int main()
{
    int n;
    cout << "Enter number of segments: " << endl;
    cin >> n;
    //creating angles and lengths array to store angles and lenghts of segments
    double angles[n];
    double lengths[n];
    theta(angles, n);
    //Inputing lengths
    cout << "Enter the lengths of the segments(greater than 0): " << endl;
    for (int i = 0; i < n; i++)
    {
        //checking for lengths greater than 0
        do
        {
            cin >> lengths[i];
        } while (lengths[i] <= 0);
    }

    //creating array of segments to store segments
    Segment arr[n];
    //Constructing the root segment
    Segment current(angles[0], lengths[0]);
    //storing root in segment array
    arr[0] = current;

    //constructing robot with rootsegment
    Robot doraemon(current);
    for (int i = 1; i < n; i++)
    {
        //creating further segments in the robot and updating the current segment
        current = current.createChild(angles[i], lengths[i]);
        //storing the segments into the segment array
        arr[i] = current;
        //adding segment into robot
        doraemon.addSegment(current);
    }
    //print the robot info
    doraemon.printRobotInfo();

    //Forward kinematics
    cout << "Forward kinematics" << endl;
    theta(angles, n);
    doraemon.forwardK(angles, arr, n);
    arr[n - 1].getEnd().printPointInfo();

    //Printing robot info after forward kinematics
    doraemon.printRobotInfo();
    //Displaying the pose
    doraemon.getGraph();

    return 0;
}