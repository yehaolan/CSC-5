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
int nFactrl(int);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float approxEx=1,exactEx,x;
    
    //Prompt the user for the power of e^x
    cout<<"What x in e^x would you like to use to"<<endl;
    cin>>x;
    //calculate e^x
    for(int n=1;n<=13;n++){
        
        approxEx+=(pow(x,n)/nFactrl(n));
    }
    
    //calculate the exact e^x
    exactEx=exp(x);
    cout<<"Approximate e^x = "<<approxEx<<endl;
    cout<<"Exact e^x = "<<exactEx<<endl;
    
    return 0;
}

int nFactrl(int n) {
    //Declare variables
    //Note:function only works for value 0 to 13
    int nFactrl=1;
    if(n==0||n==1) return nFactrl;
    else if(n<=13) {
        for(int i=2;i<=n;i++){
               nFactrl*=i;
        }
    }
    else {
        return -1;
    }
}