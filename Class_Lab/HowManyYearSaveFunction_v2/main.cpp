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
//FV=Future values $'s
//PV=Present Value $'s
//i=Interest Rate per year
//n=number of compounding periods in year
//FV        PV      i   n
float save1(float,float,int);
float save1(float,float,float=12.0f);//defaulted parameter for number of compound periods
float save2(float,float,int);
float save3(float,float,int);
float save4(float,float,int);
float save4(float,float,int);//Overloaded function called the same name
void save5(float&,float,float,float);//reference
int  save5(float&,float,float,int);//static
//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float psVal=100.0f; //$100
    float intRate=6;//Interest rate per Day
    int nCompnd=72/intRate;
    float fCompnd=nCompnd;
    float futrVal;//reference variables passed into save5
    int count;//count how many times save5 is called
    //convert interest to a fraction
    intRate=intRate/100;
    //Output the results
    cout<<"Present Value =$"<<psVal<<endl;
    cout<<"Interest Rate = "<<intRate<<"%"<<endl;
    cout<<"Our saving 1 =$";
    cout<<save1(psVal,intRate,nCompnd)<<endl;
    cout<<"Our saving 1 =$";
    cout<<save1(psVal,intRate,fCompnd)<<endl;
    cout<<"Our saving 1 =$";
    cout<<save1(psVal,intRate)<<endl;
    cout<<"Our saving 2 =$";
    cout<<save2(psVal,intRate,fCompnd)<<endl;
    cout<<"Our saving 3 =$";
    cout<<save3(psVal,intRate,fCompnd)<<endl;
    cout<<"Our saving 4 =$";
    cout<<save4(psVal,intRate,nCompnd)<<endl;
    cout<<"Our saving 4 =$";
    cout<<save4(psVal,intRate,fCompnd)<<endl;
    save5(futrVal,psVal,intRate,fCompnd);
    cout<<"Our Saving 5 = $"<<futrVal<<endl;
    
    for(int i=1;i<=5;i++) {
        count=save5(futrVal,psVal,intRate,nCompnd);
    }
    cout<<"Our Saving 5 using static= $"<<futrVal<<endl;
    cout<<"The static variables/function was called "
           <<count<<" (times)"<<endl;
     
    return 0;
}
//Inputs
//p->Principal in $'s
//i->Interest Rate per year
//n->number of compounding periods in year
//Output
//Saving -> Future value in $'s
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

void save5(float &s,float p,float i,float n){
    s=p*pow(1+i,n);
}
int save5(float& s,float p,float i,int n) {
    static int nTimCld;
    s=p*pow(1+i,n);
    return ++nTimCld;
}