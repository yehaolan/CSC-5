/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 11:30 AM
 * Purpose: My car payment
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variable
    float intRate = 0.0319f/12;//http://www.capitalone.com/auto-financing/auto-navigator/?Log=1&EventType=Link&ComponentType=G&LOB=MTS%3A%3ALCTML6KG4&PageName=Auto+Loans&PortletLocation=4%3B16-col%3B1-1-1&ComponentName=content%3B13&ContentElement=1%3B%2Fmedia%2Fbanner%2Fauto-loans%2Fauto-navigator-banner.jpg&TargetLob=MTS%3A%3ALCTML6KG4&TargetPageName=Auto+navigator&referer=https%3A%2F%2Fwww.capitalone.com%2Fauto-financing
    float msrplus = 4e4f;//Loan amount for Buick Avenir
    char nPaymnt =60;//Number of monthly payments
    //calculate the monthly payments
    float temp = pow((1+intRate),nPaymnt);
    float mPay = intRate*temp*msrplus/(temp-1);
    //output the input
    cout << "Interest per year = " << intRate*100 << "%"<< endl;
    cout << "Number of payments = " << static_cast<int>(nPaymnt) << endl;
    cout << "Loan amount = $" << msrplus << endl;
    //Output car payment
    cout << fixed <<  setprecision(2) << showpoint;
    cout << "My Avenir will cost $" << mPay << endl;
    
    return 0;
}

