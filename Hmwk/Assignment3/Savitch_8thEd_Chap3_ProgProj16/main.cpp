/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 19, 2015, 2:36 PM
 * Purpose:Homework assignment(Savitch_8thEd_Chap3_ProgProj16)
 * Find the same temperature in both Celsius and Fahrenheit
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare and initialize variables
    int cls=100;//Celsius temperature
    int fhr=212;    //Fahrenheit temperature
    //introduce this program
    cout<<"This program use do-while to find out"<<endl;
    cout<<"the same temperature in both Celsius and Fahrenheit"<<endl;
    cout<<"Press Enter to continue"<<endl;
    cin.ignore();
    //use do-while loop to find out the same temperature
    do{
        cls--;
        fhr=32+cls*9/5;  
    }while(fhr!=cls);
    //Output the result
    cout<<"The same temperature in both Celsius and Fahrenheit is "<<cls<<endl;
    
    //Exit stage right
    return 0;
}

