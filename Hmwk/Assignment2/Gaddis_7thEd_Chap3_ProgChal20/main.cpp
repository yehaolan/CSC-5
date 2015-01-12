/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 10:54 AM
 * Purpose: Homework assignment(use cmath function sin,cos,and tan
 */

//System Libraries
#include <cstdlib> //Random rand(),srand()
#include <iostream> //Keyboard/monitor I/O
#include <fstream> //File I/O
#include <ctime> //Time Functions
#include <cmath> //math function library
#include <iomanip> // format library
using namespace std;

//User Libraries

//Global Constants
const float PIDIV4 = atan(1);
const float CNVDGRD= PIDIV4/45;

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //declare a file object
    ofstream output;
    //open the file
    output.open("SinCosTan.dat");
    //declare the angle variables as an integer
    //in degrees, and the radian angle as a float
    int angDeg = rand()%361-180;//angle (-180, +180)
    float angRad = angDeg*CNVDGRD;
    //Output the angle to the screen
    output << "Angle in degrees => " << angDeg << endl;
    output << "Angle in radians => " << angRad << endl;
    //Output the sin,cos,tan
    output << fixed <<setprecision(4)<<showpoint;
    output << "sin(" << angDeg<<") = " << setw(8) << sin(angRad) << endl;
    output << "cos(" << angDeg<<") = " << setw(8) << cos(angRad) << endl;
    output << "tan(" << angDeg<<") = " << setw(8) << tan(angRad) << endl;
    //Close stream
    output.close();
    return 0;
}



