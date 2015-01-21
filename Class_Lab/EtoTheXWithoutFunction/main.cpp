/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 9:05 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float approxEx=1,exactEx,x;
    
    //Prompt the user for the power of e^x
    cout<<"What x in e^x would you like to use to"<<endl;
    cin>>x;
    //calculate e^x
    for(int n=1;n<=13;n++){
        int nFactrl=1;
        //Do the calculation for factorial
        for(int i=1;i<=n;i++){
            nFactrl*=i;
        }
        approxEx+=(pow(x,n)/nFactrl);
    }
    
    //calculate the exact e^x
    exactEx=exp(x);
    cout<<"Approximate e^x = "<<approxEx<<endl;
    cout<<"Exact e^x = "<<exactEx<<endl;
    
    return 0;
}

