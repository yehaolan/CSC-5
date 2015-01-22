/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 1:44 PM
 * Purpose: Homework assignment4(Savitch_8thEd_Chap4_ProgProj14)
 * Caloric Requirement
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
float bsMt(float weight);//basal metabolic rate calories required
float pyAt(int intenst,float weight,int time);//physical activity calories required
float calTotCl(float bsMtCal,float pyAtCal);//get the total calories should be consumed

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float weight,//(pounds)
          totCal,//total calories consumed in a meal
          bsMtCal,//calories for basal metabolic
          pyAtCal;//calories for physical activities
    int intenst, //the intensity of physical activities
        time;    //(minutes)time spent performing physical activities
    //introduce program
    cout<<"This program can calculate how many calories should get"<<endl;
    cout<<"in order to maintain the your current weight"<<endl<<endl;
    //Prompt user for weight,intensity,time for physical activity
    cout<<"Here are some sample number of intensity:"<<endl;
    cout<<"***Activity*** |"<<"***Intensity***"<<endl;
    cout<<" Running 10 mph"<<"       17"<<endl;
    cout<<" Running 6  mph"<<"       10"<<endl;
    cout<<" Basketball    "<<"        8"<<endl;
    cout<<" Walking 1  mph "<<"       1"<<endl;
    cout<<"----------input 3 information----------"<<endl;
    cout<<"1.your weight(pounds)"<<endl;
    cout<<"2.activity intensity(positive integer)"<<endl;
    cout<<"3.time for activity(minutes)"<<endl;
    cin>>weight>>intenst>>time;
    //calculate the results
    bsMtCal=bsMt(weight);
    pyAtCal=pyAt(intenst,weight,time);
    totCal=calTotCl(bsMtCal,pyAtCal);
    //Output the results
    cout<<"You need "<<bsMtCal<<" calories for basal metabolic rate"<<endl;
    cout<<"You need "<<pyAtCal<<" calories for physical activity"<<endl;
    cout<<"You need "<<totCal*0.1f<<" calories to digest food"<<endl;
    cout<<"Therefore, you need "<<totCal<<" calories consumed in one day"<<endl;
    //Exit stage right
    return 0;
}

float bsMt(float weight) {
    return 70.0f*pow(weight/2.2,0.756);
}

float pyAt(int intenst,float weight,int time) {
    return 0.0385f*intenst*weight*time;
}

float calTotCl(float bsMtCal,float pyAtCal) {
    return (bsMtCal+pyAtCal)/0.8f;
}