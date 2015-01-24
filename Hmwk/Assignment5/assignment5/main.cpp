/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 24, 2015, 12:06 PM
 * Purpose: Homework assignment5(includes 7 program)
 */

//System Libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototype
void pg1();
void pg2();
void pg3();
void pg4();
void pg5();
void pg6();
void pg7();
void getTime(short&,short&);//get the time
void cnvTime(short&,short&,char&);//convert 24-hours notation to 12
void optTime(short&,short&,char&);//output the time in 12 hours notation
void wtTime(short&,short&);//get the waiting time
void calTime(short&,short&,short,short);
void optTime2(short&,short&);


//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char ans;
    do {    
        //Output the menu
        cout<<"***************MENU***************"<<endl;
        cout<<"1.Time Conversion"<<endl;
        cout<<"2.Waiting time(24-hour notation)"<<endl;
        cout<<"3.Waiting time(12-hour notation)"<<endl;
        cout<<"4."<<endl;
        cout<<"5."<<endl;
        cout<<"6."<<endl;
        cout<<"7."<<endl;
        cout<<"0.Quit the program"<<endl;
        do {
            cout<<"Please select the program(0 to 7)"<<endl;
            cin>>ans;
            if(ans<48||ans>55)
                cout<<"Invalid input"<<endl;
        } while(ans<48||ans>55);

        switch(ans) {
            case '0': {
                cout<<"This is the end of the program"<<endl;
                break;
            }
            case '1':pg1();break;
            case '2':pg2();break;
            case '3':pg3();break;
            case '4':pg4();break;
            case '5':pg5();break;
            case '6':pg6();break;
            case '7':pg7();break;

        }
    } while(ans!='0');
    //Exit stage right
    return 0;
}

void pg1() {
    //Savitch_8thEd_Chap5_ProgProj1
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
}

void pg2() {
    //declare variables
    short hr,min;//current time
    short hrWait,minWait;//waiting hours and minutes
    
    getTime(hr,min);
    wtTime(hrWait,minWait);
    //Output the input
    cout<<endl;
    cout<<"Current time: "<<hr<<":"<<(min<10?"0":"")<<min<<endl;
    cout<<"Waiting time: "<<hrWait<<":"<<(minWait<10?"0":"")<<minWait<<endl<<endl;
    calTime(hr,min,hrWait,minWait);
    optTime2(hr,min);
}
void pg3() {
    //declare variables
    short hr,min;//current time
    short hrWait,minWait;//waiting hours and minutes
    char time=' ';//'a'or'p'
    
    getTime(hr,min);
    wtTime(hrWait,minWait);
    //Output the input
    cout<<endl;
    cout<<"Current time: "<<hr<<":"<<(min<10?"0":"")<<min<<endl;
    cout<<"Waiting time: "<<hrWait<<":"<<(minWait<10?"0":"")<<minWait<<endl<<endl;
    calTime(hr,min,hrWait,minWait);
    cnvTime(hr,min,time);
    optTime(hr,min,time);
}
void pg4() {
    
}
void pg5() {
    
}
void pg6() {
    
}
void pg7() {
    
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
    cout<<"After time conversion, the time is "<<hr<<":"<<(min<10?"0":"")<<min<<time<<"M"<<endl<<endl;
}
void wtTime(short& hrWait,short& minWait) {
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
 
void optTime2(short& hr,short& min) {
    //Output the results
    cout<<"The time after waiting period is "<<hr<<":"<<(min<10?"0":"")<<min<<endl;
}