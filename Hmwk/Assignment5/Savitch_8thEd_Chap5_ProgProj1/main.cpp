/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 22, 2015, 11:20 AM
 * Purpose: Homework assignment5(Savitch_8thEd_Chap5_ProgProj1)
 * Convert time
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void getTime(short&,short&);//get the time
void cnvTime(short&,short&,char&);//convert 24-hours notation to 12
void optTime(short&,short&,char&);//output the time in 12 hours notation

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short hr, //hour
          min;//minutes
    char time=' ';
    cout<<"Welcome to time conversion program"<<endl;
    //Prompt user for time in 24-hours notation
    getTime(hr,min);
    //time conversion
    cnvTime(hr,min,time);
    //Output the time
    optTime(hr,min,time);
    //Exit stage right
    return 0;
}

void getTime(short& hr,short& min) {
    //ask user input the hour until hr is in 0 to 23
    do {
        cout<<"First input the hour(integer from 0 to 23)"<<endl;
        cin>>hr;
        if(hr<0||hr>=24)
            cout<<"Invalid value"<<endl<<endl;
    }while(hr<0||hr>=24);
    //ask user input the minutes until min is in 0 to 59
    do {
        cout<<"Then input the minute(integer from 0 to 59)"<<endl;
        cin>>min;
        if(min<0||min>=60)
            cout<<"Invalid value"<<endl<<endl;
    }while(min<0||min>=60);
    cout<<"You input "<<hr<<":"<<(min<10?"0":"")<<min<<" in 24-hour notation"<<endl<<endl;
}

void cnvTime(short& hr,short& min,char& time) {
    if(hr==12){
        time='P';
    } else if(hr==0) {
        hr+=12;
        time='A';
    } else if(hr<12) {
        time='A';
    } else {
        hr-=12;//hour -12
        time='P';
    }
}

void optTime(short& hr,short& min,char& time) {
    //Output the result
    cout<<"After time conversion, the time is "<<hr<<":"<<(min<10?"0":"")<<min<<time<<"M"<<endl;
}