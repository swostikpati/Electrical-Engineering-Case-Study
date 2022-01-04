# Electrical Engineering Case Study - Forward Kinematics in a Robot

## Problem Identification and Statement
The objective is to build the design of a software to simulate the motion of multi-degree of
freedom kinematic chain segments attached by joints that form the structure of a robotic system.
Robot is created with a specified number of segments each having a specific angle and length
and further through the process of Forward Kinematics, the orientation of these segments in
space is altered by a new set of angles.

## Gathering of Information and Input/Output Description
### Relevant Information:
The links of the robot are modeled as rigid bodies and its joints are assumed to provide pure
rotation or translation. The robot body is composed of two parts: segments and joints.

[Picture]

A segment is a rigid member connecting two joints. As shown in Figure 1(right), a segment has
the following parameters: a starting point (x1 and y1 coordinates), a length, an angle (different
technique may have different references for measuring the angle for a segment, so make your
assumption clear), and an endpoint (x2 and y2 coordinates). Note that the coordinates of the end
point can be calculated given the start point coordinates, the length, and the angle.

A robot is comprised of a chain of segments that are connected via joints. The first segment is
called the root as it is connected to the robot base/ground. A robot can have multiple segments,
which is commonly known as the degrees of freedom.

The end effector of the robot is the end point of the last segment (noted as (x,y) in Figure 1-left).
In order to determine the position of the end effector, the position/orientation of all the segments
must be determined – which is usually controlled through the angles of the segments. The
forward kinematic analysis involves calculating the end effector position for a specific set of
angles for the segments.

Forward Kinematics is implemented as follows:\
It is customary to establish a fixed coordinate system, called the world or base frame to which all
objects including the manipulator are referenced. In this case we establish the base coordinate
frame o0x0y0 at the base of the robot, as shown in Figure below.

[Picture]

The coordinates (x, y) of the tool are expressed in this coordinate frame as

[Picture]

in which α1 and α2 are the lengths of the two links, respectively.\
(Reference: Pg. 18-19 Robot Modeling and Control by Mark W. Spong, Seth Hutchinson, and M.
Vidyasagar)

The equation above is true for a robot having two segments. Generalizing the formula for a robot
having n segments:

[Picture]

Using these equations, the end effector for a robot having n segments can be calculated and this
is how forward kinematics is implemented in the robot.

### Input Output Description
The program asks the user to input the number of segments in the robot. Based on the number of
segments, the program then prompts the user to input the angles corresponding to each segment
and the lengths of these segments. Based on these parameters a robot is created with the desired
number of segments. The user is then prompted to perform forward kinematics by entering
angles to which each segment would be updated. The output of the program is multi-fold. The
robot gives the initial end effector after the robot is created. Then, after the forward kinematics is
implemented in the robot, the new updated end effector is displayed to the user. A graph having
the pose of the robot is also created and displayed to the user. There are many other functions
that the user can perform to get more information about the segments, joints, and the robot.

## Test Cases
### Test Cases 1: 5 segments
Number of Segments: 5\
Angles(in radians): 0, 0, 0, 0, 0\
Lengths: 123, 32, 55, 67, 89\
The output of the initial position of the End Effector should
be: (366,0)\
New Angles(in radians): 1.57 0 0 0 0\
The output of the new position of the End Effector should be:
(0, 366)

### Test Cases 2: 4 segments
Number of Segments: 4\
Angles(in radians): 8,5,8,10\
Lengths: 4.0, 8.9, 9.5, 9.65\
The output of the initial position of the End Effector should
be: (11.11,11.74)\
New Angles(in radians): 0.75 0 0 0\
The output of the new position of the End Effector should be:
(23.45,21.84)

### Test Cases 3: 3 Segments
Number of Segments: 3\
Angles(in radians): 7,5,8\
Lengths: -5.6(value doesn’t allow), 6, 8, 6.7\
The output of the initial position of the End Effector should
be: (14, 5.7)\
New Angles(in radians): 2, 8, -0.67\
The output of the new position of the End Effector should be:
(-15.8, 1.73)

### Test Cases 4: 2 Segments
Number of Segments: 2\
Angles(in radians): 0,0\
Lengths: 45, 55\
The output of the initial position of the End Effector should
be: (100, 0)\
New Angles(in radians): 0, 0\
The output of the new position of the End Effector should be:
(-100, 0)

### Test Cases 5: 5 Segments
Number of Segments: 5\
Angles(in radians): 1.47,0,0,0,0\
Lengths: 10, 15, 20, 25, 30\
The output of the initial position of the End Effector should
be: (10, 99.4)\
New Angles(in radians): 0.75, 0.75, 1.47, 1.0,0.30\
The output of the new position of the End Effector should be:
(-41, -20.3)

##  Software Testing and Verification

[To be updated]

## User Guide
The program will help create a multi-degree of freedom robot having any number of segments as
desired by you. You will be required to first input the number of segments you wish to have for
the robot. Then you will be prompted to input the angles in radians and the lengths of each
segment. The program will provide you with the details of the robot created and ask you for
inputting further angles for implementing forward kinematics. Based on your inputs, the angle of
each segment would be updated and a new end effector will be displayed to you. A graph having
the pose of the robot will also be generated and displayed.

## References
PbPlots: https://github.com/InductiveComputerScience/pbPlots/tree/master/Cpp

Forward Kinematics: M. W. Spong, S. Hutchinson and M. Vidyasagar, “Robot Modeling and
Control”, First Edition, John Wiley & Sons INC. (Page 18-19)



