/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 11:00 PM
 * Purpose: Homework assignment4(Savitch_8thEd_Chap4_ProgProj4)
 * Inflation rate
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void InfRt(float lsYrPri,float nowPri);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float lsYrPri, //the price in the last year
          nowPri;  //Today price
    string item;
    //introduce the program
    cout<<"This program gauge the rate of inflation for the past year"<<endl;
    //Prompt user for the price in the last year and today of an item
    cout<<"Please input an item name you would like to gauge the rate of inflation"<<endl;
    cin>>item;
    cout<<"Input the price of "<<item<<" one year ago"<<endl;
    cin>>lsYrPri;
    cout<<"Input the price of "<<item<<" today"<<endl;
    cin>>nowPri;
    //calculate and display the results
    InfRt(lsYrPri,nowPri);
    //Exit stage right
    return 0;
}

void InfRt(float lsYrPri,float nowPri) {
    cout<<setprecision(2)<<fixed;
    cout<<"The rate of inflation is "<<(nowPri-lsYrPri)/lsYrPri*100<<"%"<<endl;
}