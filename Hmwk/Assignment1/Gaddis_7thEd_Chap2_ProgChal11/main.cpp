/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 8, 2015, 11:17 AM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap2_ProgChal11)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char gas=20;//A car with 20-gallon gas
    float disTwPG = 21.5,//The distance in town per gallon
          disHwPG = 26.8;//The distance on highway per gallon
    short disTw,//The distance of drive in town with a tank of gas
          disHw;//The distance of drive on highway with a tank of gas
          
    //calculate the distances
    disTw = gas*disTwPG;
    disHw = gas*disHwPG;
    
    //Output the results
    cout << "With one tank of gas(20 gallons),\n";
    cout << "The distance that the car can be driven in town is "<< disTw;
    cout << " miles."<< endl;
    cout << "The distance that the car can be driven on highway is "<< disHw;
    cout << " miles."<< endl;
    
    //Exit stage right
    return 0;
}

