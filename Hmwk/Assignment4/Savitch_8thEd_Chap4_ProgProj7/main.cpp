/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 11:14 AM
 * Purpose: Gravitational attractive force
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float G=6.673e-8f;//gravitational constant cm^3/g/sec^2

//Function prototypes
//F             m1     m2   d
float atrForc(float,float,float);

//Execution begins here
int main(int argc, char** argv) {
    //declare variable, variables found from Google
    float mEarth=5.972e24f;//mass of earth in Kilograms
    float wtMark=188.0f;//Weight of Mark in lbs
    float rEarth=6.371e3;//radius of earth in kilometers
    //Conversion for consistent units
    mEarth*=1e3;//convert to gram -> 10^3g/kg
    float mMark=wtMark*453.59;//453.59g/lbs
    rEarth*=(1e3f*1e2f);//10^3m/km  10^3cm/m
    //calculate the attractive force in dynes
    float dynes=atrForc(mEarth,mMark,rEarth);
    float lbs=dynes/4.44822e5f;//conversion 1lb/4dynes
    //Output the results
    cout<<"My weight in dynes = "<<dynes<<endl;
    cout<<"My weight in pounds = "<<lbs<<endl;
    
    return 0;
}

float atrForc(float m1,float m2,float d) {
    return G*m1*m2/d/d;
}