/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 20, 2015, 8:11 PM
 * Purpose: Homework assignment4Savitch_8thEd_Chap4_ProgProj9)
 * Clothing size
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void getHat(float weight,float height);
void getJkt(float weight,float height,short age);
void getWst(float weight,short age);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float height, //in inches
          weight, //in pounds
          hat,    //hat size
          jacket, //jacket size
          waist;  //waist size
    unsigned short age;
    //introduce the program
    cout<<"This program can calculate your clothing"<<endl;
    cout<<"sizes with your height,weight and age"<<endl;
    cout<<"Press Enter to continue"<<endl;
    cin.ignore();
    //Prompt user for height, weight, and age
    cout<<"Please input your weight(pounds), height(inches),and age"<<endl;
    cin>>height>>weight>>age;
    //use a function to calculate and display the hat size at one time
    getHat(weight,height);
    //use a function to calculate and display the jacket size at one time
    
    
    //Exit stage right
    return 0;
}

void getHat(float weight,float height) {
    cout<<"Your hat size is "<<(2.9*weight/height)<<" inches"<<endl;
}

void getJkt(float weight,float height,short age) {
    float jacket;//jacket size
    jacket=height*weight/288;
    for(int i=39;i<=age;i++) {
        if(i%10==0)
            jacket+=(1.0f/8);
    }
    cout<<"Your jacket size is "<<jacket<<" inches"<<endl;
}

void getWst(float weight,short age) {
    float waist;//waist size
    waist=weight/5.7;
    for(int i=29;i<=age;i++){
        if(i%2==0)
            waist+=0.1;
    }
    cout<<"Your waist size is "<<waist<<" inches"<<endl;
}