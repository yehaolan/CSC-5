/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 20, 2015, 5:13 PM
 * Purpose: Homework assignment(Savitch_8thEd_Chap4_ProgProj8)
 * New House After-tax cost
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float caLoan(float pri,float dnPay);//the function to calculate the loan
float caCost(float loan);//the function to calculate the annual cost
//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float price,   //the price of the house($)
          downPay, //down payment of the house($)
          loan,    //the loan of house($)
          cost;    //annual after-tax cost of new house($)
    //Prompt user for price and down payment
    do {
        cout<<"Input the price of your house($)"<<endl;
        cout<<"Please input the positive number"<<endl;
        cin>>price;
        if(price<=0)
            cout<<"Invalid input"<<endl;
    }while(price<=0);
    do {
        cout<<"Input the down payment of your house($)"<<endl;
        cout<<"Please input the positive number"<<endl;
        cin>>downPay;
        if(downPay<=0)
            cout<<"Invalid input"<<endl;
    }while(downPay<=0);
    //calculate the loan
    loan=caLoan(price,downPay);
    //calculate the cost
    cost=caCost(loan);
    //Output the results
    cout<<"The loan is $"<<loan<<endl;
    cout<<"The annual after-tax cost of new house is $"<<cost<<endl;
    //Exit stage right
    return 0;
}

float caLoan(float pri,float dnPay) {
    return (pri-dnPay);
}

float caCost(float loan) {
    return (loan*0.03+loan*0.06*(1-0.35));
}