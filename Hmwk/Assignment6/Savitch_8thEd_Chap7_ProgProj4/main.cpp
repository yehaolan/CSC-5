/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 3, 2015, 11:01 PM
 * Purpose: Savitch_8thEd_Chap7_ProgProj4
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global constants

//Function Prototypes
float calSD(const float[],int);
//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE=100; //the size of array
    float array[SIZE];  
    int num;//the number of number user wants to input
    float sd;//standard deviation
    //Prompt user for number of inputs
    cout<<"Input the number of inputs you would"<<endl;
    cout<<"like to calculate standard deviation"<<endl;
    cout<<"Note: An positive integer less than 100"<<endl;
    cin>>num;
    //Prompt user for input the elements of array
    cout<<"Please fill the array"<<endl;
    for(int i=0;i<num;i++) {
        cout<<(i+1)<<": ";
        cin>>array[i];
    }
    sd=calSD(array,num);
    cout<<"The standard deviation of these number is "<<sd<<endl;
    //Exit stage right
    return 0;
}

float calSD(const float a[],int n) {
    float ave=0;//average of all numbers
    float sd=0;//standard deviation
    float temp=0;
    for(int i=0;i<n;i++) {
        ave+=a[i];
    }
    ave/=n; //get the average of numbers
    //record calculation with temp
    for(int i=0;i<n;i++) {
        temp+=(a[i]-ave)*(a[i]-ave);
    }
    sd=sqrt(temp/n);
    return sd;
}