/* 
 * File:   main.cpp
 * Author: Haolan Ye
 * Created on January 7, 2015, 11:38 AM
 * Purpose: How easy computer can make mistake
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare 3 variable
    float a,b,c;
    //Prompt for a and b
    cout<<"Input 2 float values"<<endl;
    cin>>a>>b;
    //Sum the values
    c = a + b;
    //Output the results
    cout << c << " = " << a << " + "<< b << endl;

    return 0;
}
