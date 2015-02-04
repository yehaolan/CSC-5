/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on Feb 3, 2015, 10:10 AM
 * Purpose:Developing bubble sort
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
void swap(int &,int &); //with exclusive words
void bblSort(int[],int);//with swap function
void bublSrt(int[],int);//without swap function

//Execution begins here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //declare variables and arrays
    const int SIZE=100000;
    int pFilRow=100000,perLine=10;
    int array[SIZE]={};
    //fill the array
    filAray(array,pFilRow);
    //print the array
    prntAry(array,pFilRow,perLine);
    //test out swap min
    bublSrt(array,pFilRow);
    //print the array
    prntAry(array,pFilRow,perLine);
    //Exit stage right
    return 0;
}

void swap(int &a,int &b) {
    //in place swap using logical exclusive or's
    a=a^b;
    b=a^b;
    a=a^b;
}

void bblSort(int a[],int n) {
    //declare a swap variables
    bool bSwap;
    //do while swap has occurred
    do {
        bSwap=false;
        for(int i=0;i<n-1;i++) {
            if(a[i]>a[i+1]) {
                swap(a[i],a[i+1]);
                bSwap=true;
            }
        }
    }while(bSwap);
}

void bublSrt(int a[],int n) {
    //declare a swap variables
    bool bSwap;
    //do while swap has occurred
    do {
        bSwap=false;
        for(int i=0;i<n-1;i++) {
            if(a[i]>a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                bSwap=true;
            }
        }
    }while(bSwap);
}
//print perLine col for the array output by row
void prntAry(const int a[],int n,int perLine) {
    cout<<endl<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}
//Randomly fill the array which makes it sorted
void filAray(int a[],int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
}