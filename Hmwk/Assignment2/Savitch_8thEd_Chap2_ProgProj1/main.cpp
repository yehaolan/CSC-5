/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 13, 2015, 10:51 AM
 * Purpose: Metric conversion
 */

//System Libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants
const float CMTNONS = 3.527392e4f;//conversion from Metric Tons to Ounces

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float wtPackOz,  //weight of cereal contents in ounces
          wtPackTn,  //weight of cereal contents in tons
          nPackTn;   //number of cereal boxes in a metric ton
    char answer;
    //Prompt user for cereal weight
    cout << "Input the number ounces on the cereal" << endl;
    cout << "box to convert to metric tons." << endl;
    cout << "Format is float ddd.ddd(onuces)" << endl;
    cin >> wtPackOz;
    //calculate the results
    wtPackTn = wtPackOz/CMTNONS;
    nPackTn = 1/wtPackTn;
    //Output the results
    cout << "Weight of cereal box is " << wtPackTn << " Metric Tons." << endl;
    cout << "Number of cereal box in a metric ton => " << nPackTn << endl;
    
    //Ask if user would like to repeat the calculation
    cout << "Would you like to repeat the calculation?" <<endl;
    cout << "Or make a new calculation?" << endl;
    cout << "Type Y for yes and N for no." << endl;
    cin >> answer;
    
    if(answer=='Y'||answer == 'y') {
        //Prompt user for cereal weight
        cout << "Input the number ounces on the cereal" << endl;
        cout << "box to convert to metric tons." << endl;
        cout << "Format is float ddd.ddd(onuces)" << endl;
        cin >> wtPackOz;
        //calculate the results
        wtPackTn = wtPackOz/CMTNONS;
        nPackTn = 1/wtPackTn;
        //Output the results
        cout << "Weight of cereal box is " << wtPackTn << " Metric Tons." << endl;
        cout << "Number of cereal box in a metric ton => " << nPackTn << endl;
    }
    
    //Exit stage here
    return 0;
}

