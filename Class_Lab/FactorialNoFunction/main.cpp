/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 8:52 AM
 * Purpose: factorial
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants


//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int nFactrl=1,n;
    //Prompt user for the factorial
    cout<<"What N would you like to use to"<<endl;
    cout<<"calculate the factorial"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        nFactrl*=i;
    }
    //Output the result
    cout<<n<<"! = "<<nFactrl<<endl;
    return 0;
}

