/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 24, 2015, 9:19 AM
 * Purpose: Homework assignment(Savitch_8thEd_Chap5_ProgProj2)
 * Waiting Time in 24-hour notation
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
void getTime(short&,short&,short&,short&);
void calTime(short&,short&,short,short);
void optTime(short&,short&);
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short hr,min;//current time
    short hrWait,minWait;//waiting hours and minutes
    getTime(hr,min,hrWait,minWait);
    calTime(hr,min,hrWait,minWait);
    optTime(hr,min);
    
    //Prompt user for current time and waiting time
    //Exit stage right
    return 0;
}

void getTime(short& hr,short& min,short& hrWait,short& minWait) {
    //prompt user for current time
    cout<<"What is the current time in 24-hour notation?"<<endl;
    do { //get current hours
        cout<<"First input the hour(integer from 0 to 23)"<<endl;
        cin>>hr;
        if(hr<0||hr>=24)
            cout<<"Invalid input"<<endl<<endl;
    } while(hr<0||hr>=24);
    do {  //get current minutes
        cout<<"Then input the minute(integer from 0 - 59)"<<endl;
        cin>>min;
        if(min<0||min>=60)
            cout<<"Invalid input"<<endl<<endl;
    }while(min<0||min>=60);
    cout<<endl;
    //Prompt user for waiting time
    cout<<"How long is your waiting time?";
    do { //get waiting hours
        cout<<"First input the hour(integer from 0 to 23)"<<endl;
        cin>>hrWait;
        if(hrWait<0||hrWait>=24)
            cout<<"Invalid input"<<endl<<endl;
    } while(hrWait<0||hrWait>=24);
    do {  //get waiting minutes
        cout<<"Then input the minute(integer from 0 - 59)"<<endl;
        cin>>minWait;
        if(minWait<0||minWait>=60)
            cout<<"Invalid input"<<endl<<endl;
    }while(minWait<0||minWait>=60);
    //Output the input
    cout<<endl;
    cout<<"Current time: "<<hr<<":"<<(min<10?"0":"")<<min<<endl;
    cout<<"Waiting time: "<<hrWait<<":"<<(minWait<10?"0":"")<<minWait<<endl<<endl;
}

void calTime(short& hr,short& min,short hrWait,short minWait) {
    //when minute over or equal 60 mins,minus 60 mins and hours +1
    min+=minWait;
    if(min>=60) {
        min-=60;
        hr++;
    }
    hr+=hrWait;
    if(hr>23)
        hr-=24;
}
 
void optTime(short& hr,short& min) {
    //Output the results
    cout<<"The time after waiting period is "<<hr<<":"<<(min<10?"0":"")<<min<<endl;
}