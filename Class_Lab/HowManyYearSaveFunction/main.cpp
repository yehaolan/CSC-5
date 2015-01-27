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

//Function Prototypes
//FV = Future Value $'s
//PV = Present Value $'s
// i = Interest Rate per year
// n = Number of compounding periods in years
//FV         PV     i    n
float save1(float,float,int);
float save1(float,float,float=12.0f);//Defaulted Parameter for number of compounding periods
float save2(float,float,int);
float save3(float,float,int);
float save4(float,float,int);
float save4(float,float,float);//Overloaded function call, i.e. same name

int main(int argc, char** argv) {
    //Declare and initialize values
    float prsVal=100.0f;//$100
    float intRate=6;//% Interest rate per year
    int   nCompnd=72/intRate;//By the of 72 to double
    float fCompnd=nCompnd;
    //Convert interest to a fraction
    intRate/=100;
    //Output the inputs
    cout<<"Present Value = $"<<prsVal<<endl;
    cout<<"Interest Rate =  "<<intRate*100
            <<"%"<<endl;
    cout<<"Number of compounding Periods = "
            <<nCompnd<<"(years)"<<endl;
    //Output the Future value
    cout<<"Our Savings 1 = $"
            <<save1(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 1 = $"
            <<save1(prsVal,intRate,fCompnd)<<endl;
    cout<<"Our Savings 1 = $"
            <<save1(prsVal,intRate)<<endl;
    cout<<"Our Savings 2 = $"
            <<save2(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 3 = $"
            <<save3(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 4 = $"
            <<save4(prsVal,intRate,nCompnd)<<endl;
    cout<<"Our Savings 4 = $"
            <<save4(prsVal,intRate,fCompnd)<<endl;
    //Exit Stage Right!
    return 0;
}

//Inputs
//p->Principal in $'s meaning present value
//i->Interest rate per year
//n->Number of compounding periods
//Output
//Savings->Future value in $'s
float save1(float p,float i,int n){
    return p*pow(1+i,n);
}

float save1(float p,float i,float n){
    return p*pow(1+i,n);
}

float save2(float p,float i,int n){
    return p*exp(n*log(1+i));
}

float save3(float p,float i,int n){
    for(int year=1;year<=n;year++){
        p*=(1+i);
    }
    return p;
}

float save4(float p,float i,int n){
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}

float save4(float p,float i,float n){
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}