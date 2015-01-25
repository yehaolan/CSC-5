/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 24, 2015, 12:06 PM
 * Purpose: Homework assignment5(includes 7 program)
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User libraries

//Global Constants
const short DIM=10;//dimes
const short QRT=25;//quarter
const float MPRF=0.3048;//meters per foot
const short CMPRM=100;//centimeter per meter
const short ICPRF=12;//inches per foot

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
void calDev(short,short,short,short);
void calCoin(short);
void getLth(short&,short&);
void cnvLth(short,short,float&,float&);
void optLth(short,short,float,float);
void calRst(short,short,short,short&,float&);

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
        cout<<"4.Number Deviation"<<endl;
        cout<<"5.Coin Change"<<endl;
        cout<<"6.Length conversion"<<endl;
        cout<<"7.Triangle Area and Perimeter"<<endl;
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
        if(ans!='0') {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
            cin.ignore();
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
    //Savitch_8thEd_Chap5_ProgProj2
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
    //Savitch_8thEd_Chap5_ProgProj3
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
    //Savitch_8thEd_Chap5_ProgProj4
    //declare variables
    short a,b,c,d;
    //introduce program
    cout<<"Welcome to Standard deviation"<<endl;
    //Prompt user for 4 numbers
    cout<<"This program calculates the deviation of 4 numbers"<<endl;
    cout<<"Input 4 numbers"<<endl;
    cin>>a>>b>>c>>d;
    //calculate and display the deviation of 4 numbers
    calDev(a,b,c,d);
}
void pg5() {
    //Savitch_8thEd_Chap5_ProgProj5
    //declare variables
    short amt;//the amount of cents user would like to change
    cout<<"Welcome to Coin Change"<<endl;
    do {
        cout<<"Input the amount of cents you would like to change(1 to 99)"<<endl;
        cin>>amt;
        if(amt<1||amt>99)
            cout<<"Invalid input"<<endl;
    } while(amt<1||amt>99);
    calCoin(amt);
}
void pg6() {
    //Savitch_8thEd_Chap5_ProgProj6
    //declare variables
    short feet,inch;
    float meter;
    float cenMe;//centimeter
    //introduce program
    cout<<"Welcome to length conversion"<<endl;
    cout<<"Feet and inches -> meters and centimeter"<<endl;
    getLth(feet,inch);
    cnvLth(feet,inch,meter,cenMe);
    optLth(feet,inch,meter,cenMe);
}
void pg7() {
    //Savitch_8thEd_Chap5_ProgProj13
    //declare variables
    short a,b,c;//the length of three sides of triangle
    short prmt;//perimeter of triangle
    float area;//area of triangle
    //Prompt user for three sides of triangles
    do {
        cout<<"Input the length of three sides of triangle(integer)"<<endl;
        cin>>a>>b>>c;
        if(a+b<=c||a+c<=b||b+c<=a)
            cout<<"This is not triangle! Please input again"<<endl<<endl;
    } while(a+b<=c||a+c<=b||b+c<=a);
    
    calRst(a,b,c,prmt,area);
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

void calDev(short a,short b,short c,short d) {
    //declare and calculate average of 4 numbers
    float aver=(a+b+c+d)/4.0f;//average of 4 numbers
    //calculate deviation
    float dev=sqrt((aver-a)*(aver-a)+(aver-b)*(aver-b)+(aver-c)*(aver-c)+(aver-d)*(aver-d)/4);
    cout<<"The deviation of "<<a<<","<<b<<","<<c<<","<<d<<" is "<<dev<<endl;
}

void calCoin(short amt) {
    //declare variables
    short p;//the number of pennies
    short d;//the number of dimes
    short q;//the number of quarters
    q=amt/QRT;
    d=(amt-q*QRT)/DIM;
    p=amt-q*QRT-d*DIM;
    cout<<amt<<" cents can be given as"<<endl;
    cout<<q<<" quarter(s) "<<d<<" dime(s) and "<<p<<" penny(pennies)"<<endl;
}

void getLth(short& feet,short& inch) {
    //Prompt user for feet and inches
    cout<<"Input a length in feet and inches"<<endl;
    cout<<"Note: They both should be positive integer"<<endl;
    cin>>feet>>inch;
}
void cnvLth(short feet,short inch,float& meter,float& cenMe) {
    //convert to meters and centimeters
    meter=(static_cast<float>(inch)/ICPRF+feet)*MPRF;
    cenMe=(meter-static_cast<short>(meter))*CMPRM;
    meter=static_cast<short>(meter);
}
void optLth(short feet,short inch,float meter,float cenMe) {
    cout<<feet<<" feet "<<inch<<" inches is "<<endl;
    cout<<meter<<" meters "<<cenMe<<" centimeters"<<endl;
}
void calRst(short a,short b,short c,short& prmt,float& area) {
    //declare variables
    float s;//half of perimeter of triangle
    prmt=a+b+c;
    s=prmt/2.0f;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<setprecision(2)<<fixed;
    cout<<"The perimeter of the triangle is "<<prmt<<endl;
    cout<<"The area of the triangle is "<<area<<endl;
}