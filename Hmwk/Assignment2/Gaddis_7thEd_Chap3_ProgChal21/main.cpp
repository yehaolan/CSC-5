/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 2:14 PM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap3_ProgChal21)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global constants
const char CONVPT = 100;
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char cmsPer = 2;//The percentage of commission for transaction
    short shrNum = 1000;//the amount of shares that Joe bought      
    float byPrShr = 32.87,// the price of each share when buy
            sdPrshr = 33.92,//// the price of each share when sold
            cmsBuy,//the amount of commission when buy
            cmsSod,//the amount of commission when sold
            prf,   //profit after selling stock and paying two commissions
            stkSod,//the amount of money when he sold the stock
            stkPrc;//the amount of money when he bought the stock
    
    //calculate the result
    stkPrc = shrNum*byPrShr;            //how much he paid for stock
    cmsBuy = stkPrc*cmsPer/CONVPT;      //how much he paid for cms when buy stock
    stkSod = shrNum*sdPrshr;            //how much he sold for stock
    cmsSod = stkSod*cmsPer/CONVPT;      //how much he paid for cms when sold stock
    prf = stkSod-stkPrc-cmsBuy-cmsSod;  //profit
    
    //output the results
    cout << setprecision(2) <<fixed;
    cout << "The amount of money Joe paid for the stock is $" << stkPrc << endl;
    cout << "The amount of commission Joe paid his broker" << endl;
    cout << "when he bought the stock is $" << cmsBuy <<endl;
    cout << "The amount that Joe sold the stock for is $" << stkSod <<endl;
    cout << "The amount of commission Joe paid his broker" << endl;
    cout << "when he sold the stock is $" << cmsSod << endl;
    cout << "the amount of profit that Joe made after selling his stock" << endl;
    cout << "and paying the two commissions to his broker is "<<prf <<" dollars.\n";
    if(prf>=0)
        cout << "That means he won " << abs(prf) << " dollars.\n";
    else 
        cout << "That means he lost " << abs(prf) << " dollars.\n";
    //Exit stage right
    return 0;
}

