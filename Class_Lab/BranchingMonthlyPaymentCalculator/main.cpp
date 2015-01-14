/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 14, 2015, 7:28 AM
 * Purpose:
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float i;//Interest Rate per cent per year
    float t;//temp variables
    float l;//loan amount in dollar
    unsigned short n;//number of month
    float mp;//monthly payment in dollar
    
    //Input the variables required
    cout << "What's the interest rate in per cent per year?" << endl;
    cin >> i;
    i/=(100*12);//Convert to decimal
    cout << "What's the loan amount $'s(float format)?" << endl;
    cin >> l;
    cout << "Number of monthly payment ( format integer)" << endl;
    cin >> n;
    //calculate the monthly payment
    if(i<=0) {
        mp = l/n;
    } else {
        t = pow(1+i,n);
        mp = i*t*l/(t-1);
    }
    //Display the results
    cout << setprecision(2) << fixed;
    cout << "Your monthly payment = $" << mp << endl;
    //Exit stage right
    return 0;
}

