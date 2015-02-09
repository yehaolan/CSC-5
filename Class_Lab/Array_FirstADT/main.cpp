/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 9, 2015, 8:45 AM
 * Purpose: Test the Array ADT
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array *filAray(int);
void prntAry(const Array *,int);
void destroy(Array *);

//Execution Begins here
int main(int argc, char** argv) {
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array ADT
    int size=100,perLine=10;
    Array *array=filAray(size);
    //Print the array
    prntAry(array,perLine);
    //Clean up
    destroy(array);
    //Exit stage right
    return 0;
}

Array *filAray(int n) {
    //Make sure valid size for the array
    if(n<=0) return 0;
    //Dynamically create array ADT
    Array *a=new Array;
    //Fill the array ADT
    a->size=n;
    //Now declare and allocate memory for the data
    a->data=new int[a->size];
    //Fill data with 2 digit numbers
    for(int i=0;i<a->size;i++) {
        a->data[i]=rand()%90+10;
    }
    return a;
}
void prntAry(const Array *a,int perLine) {
    cout<<endl;
    for(int i=0;i<a->size;i++) {
        cout<<a->data[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}
void destroy(Array *a) {
    delete [] a->data;
    delete a;
}