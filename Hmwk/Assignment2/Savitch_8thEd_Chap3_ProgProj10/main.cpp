/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 19, 2015, 11:27 AM
 * Purpose:Homework assignment(Savitch_8thEd_Chap3_ProgProj10) Fibonacci
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
    unsigned int initPo;//initial population
    unsigned int lstTwoP;//last two population
    unsigned int lastPo=0;//last population
    unsigned int currPo;//current population
    short day;
    //introduce the program
    cout<<"The Fibonacci series applies to green crud population"<<endl;
    cout<<"The population is the same for 4 days and then increase every fifth day"<<endl;
    //Prompt user for initial population
    do {
        cout<<"Input the initial population(in pounds)"<<endl;
        cout<<"Note:Input positive integer between 1 and 100"<<endl;
        cin>>initPo;
    } while(initPo<1||initPo>100);
    //Prompt user for the number of days
    do {
        cout<<"Input the number of days"<<endl;
        cout<<"Note:Input positive integer between 1 and 100"<<endl;
        cin>>day;
    } while(day<1||day>100);
    //initial population assign to last two population
    lstTwoP=initPo;
    //user for loop to calculate the population at a certain day
    for(int i=0;i<=day;i++){
        //every fifth days
        if(i%5==0) {
            currPo=lstTwoP+lastPo;//equal to the total of last two days 
            lstTwoP=lastPo;
            lastPo=currPo;
            cout<<"Day"<<i<<": "<<currPo<<" pounds"<<endl; 
        } else {
            //the other day
            currPo=lastPo;//the same of last day's
            cout<<"Day"<<i<<": "<<currPo<<" pounds"<<endl;
        }
        
    }
    //Exit stage right
    return 0;
}

