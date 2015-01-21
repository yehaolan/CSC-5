/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 8:19 AM
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
const unsigned int MAXRAND=pow(2,31);

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //set the seed 
    srand(static_cast<unsigned int>(time(0)));
    //declare a max variable
    int loop=100000000;
    int max=rand();
    //Now loop to find the maximum random number
    for(int i=2;i<=loop;i++) {
        int r=rand();
        if(r>max) max=r;
        
    }
    //Now output the result
    cout<<"2^31 = "<<MAXRAND<<endl;
    cout<<"The maximum found = "<<max<<endl;
    return 0;
}

