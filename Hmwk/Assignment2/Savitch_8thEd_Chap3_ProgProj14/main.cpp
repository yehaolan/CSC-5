/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 19, 2015, 3:03 PM
 * Purpose:Homework assignment(Savitch_8thEd_Chap3_ProgProj14)
 * Prime number
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //introduce program
    cout<<"This program finds and prints all the prime number s between 3 and 100"<<endl;
    cout<<"Press Enter to continue"<<endl;
    cin.ignore();
    //the outer loop is to count from 3 to 100
    for(int num=3;num<=100;num++){ 
        //the inner loop to check if this number is prime number
        for(int div=2;div<num;div++){
            //if number can be divided by divisor, means this number is not prime number
            if(num%div==0)
                break;
            else if(num==div+1) {
                //when until number equal to divisor+1,means this number is prime number, so output
                cout<<num<<endl;
            }
        }
    }
    //Exit stage right
    return 0;
}

