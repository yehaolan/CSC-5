/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on Feb 3, 2015, 9:00 AM
 * Purpose:Developing mark sorting
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
void swapMin(int,int[],int);//swap as you go
void mrkSort(int[],int);//mark sort
void markSort(int[],int);//mark sort in one function

//Execution begins here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //declare variables and arrays
    const int SIZE=100000;
    int pFilRow=1000,perLine=10;
    int array[SIZE]={};
    //fill the array
    filAray(array,pFilRow);
    //print the array
    prntAry(array,pFilRow,perLine);
    //test out swap min
    markSort(array,pFilRow);
    //print the array
    prntAry(array,pFilRow,perLine);
    
    //Exit stage right
    return 0;
}

void markSort(int a[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]>a[j]) {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        } 
    }
}

void swap(int &a,int &b) {
    //in place swap using logical exclusive or's
    a=a^b;
    b=a^b;
    a=a^b;
}

void swapMin(int pos,int a[],int n) {
    //swap as you go to place the min element at the top of list
    for(int i=pos+1;i<n;i++) {
        if(a[pos]>a[i]) swap(a[pos],a[i]);
    }
}

void mrkSort(int a[],int n) {
    //apply swapMin from beginning to end
    for(int i=0;i<n-1;i++) {
        swapMin(i,a,n);
    }
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