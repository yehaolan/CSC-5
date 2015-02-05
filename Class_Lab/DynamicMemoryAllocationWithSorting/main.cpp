/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 5, 2015, 10:01 AM
 * Purpose:Illustrate dynamic memory with a sort
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int *filAray(int);
void prntAry(int *,int,int);
void destroy(int *);
void swap(int [],int *);
//void swap(int &,int &);
int * markSrt(int *,int);
//Execution begins here
int main(int argc, char** argv) {
    //initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //declare and initialize an array
    int size=100;
    int *array=filAray(size);
    //print the array
    prntAry(array,size,10);
    //sort the array
    int *brray=markSrt(array,size);
    prntAry(brray,size,10);
    //sort the array
    destroy(array);
    destroy(brray);
    //Exit stage right
    return 0;
}
int * markSrt(int *a,int n) {
    //Allocate memory for a copy of the data
    if(n<=1) return 0;
    int *b=new int[n];
    //copy the information
    for(int i=0;i<n;i++) {
        *(b+i)=a[i];
    }
    //Sort the array
    for(int pos=0;pos<n-1;pos++) {
        for(int lst=pos+1;lst<n;lst++) {
            if(b[pos]>*(b+lst)) swap(b[pos],*(b+lst));//swap(int &,int &)
            //if(*(b+pos)>b[lst]) swap(&b[pos],(b+lst));//swap(int *,int *)
        }
    }
    //return the result
    return b;
}

void prntAry(int *a,int n,int pl) {
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<*(a+i)<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl;
}


//fill a dynamic array with two digit random numbers
int *filAray(int n) {
    //allocate the memory
    if(n<=1) return 0;
    int *a=new int[n];
    //fill with random number
    for(int i=0;i<n;i++) {
        *(a+i)=rand()%90+10;
    }
    return a;
}

void destroy(int *a) {
    delete []a;
}

void swap(int *x,int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}
void swap(int &x,int &y) {
    int temp=x;
    x=y;
    y=temp;
}