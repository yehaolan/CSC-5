/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 8, 2015, 7:49 AM
 * Purpose: 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const char CONVPCT=100;//Percent conversion

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short custSrv=12467; //Customers Surveyed
    char perEDrk=14; //Percentage Energy drinkers
    char perCDrk=64;//Percentage Citrus Drinkers
    //calculate customer requested
    short custE=custSrv*perEDrk/CONVPCT;//energy drinkers
    short custC=custE*perCDrk/CONVPCT;//Citrus Drinker
    //output the results
    cout<<"Customers surveyed that are Energy Drinkers = ";
    cout<<custE<<endl;
    cout<<"Customers surveyed that are Citrus Drinkers = ";
    cout<<custC<<endl;
    //Exit stage right
    return 0;
}

