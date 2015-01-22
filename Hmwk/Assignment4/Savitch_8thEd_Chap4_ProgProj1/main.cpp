/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 20, 2015, 1:15 PM
 * Purpose: Homework assignment4(Savitch_8thEd_Chap4_ProgProj1)
 * Miles Per Gallon
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const float LPRGALN=0.264179;//gallons per liter

//Function Prototypes
float calMPG(float liter,float dstenc);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float gsl;//gasoline of the car
    float dis;//distance
    float mpg;//mile per gallon
    //Prompt user for liters of gasoline of car and the distance
    do {    
        cout<<"Input the number of liters of gasoline consumed by your car"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>gsl;
        if(gsl<=0)
            cout<<"Invalid input"<<endl;
    }while(gsl<=0);
    do {
        cout<<"Input the distance traveled by your car(in miles)"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>dis;
    }while(dis<=0);
    //calculate the result with function
    mpg=calMPG(gsl,dis);
    //Output the result
    cout<<setprecision(2)<<fixed;
    cout<<"With 1 gallon gasoline, your car can travel "<<mpg<<" miles"<<endl;
    //Exit stage right
    return 0;
}

float calMPG(float liter,float dstenc) {
    return dstenc*LPRGALN/liter;
}