/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on Feb 3, 2015, 11:15 AM
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
void filAray(int [],int [],int);
void prntAry(const int [],const int[],int,int);
void prntAry(const int [],int,int);
void swap(int &,int &); //with exclusive words
void markSort(const int[],int [],int);//mark sort in one function

//Execution begins here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //declare variables and arrays
    const int SIZE=100000;
    int pFilRow=100,perLine=10;
    int array[SIZE]={};
    int indx[SIZE]={};
    //fill the array
    filAray(array,indx,pFilRow);
    //print the original array
    cout<<"Display Original Array Before Sorting:"<<endl;
    prntAry(array,indx,pFilRow,perLine);
    //test out swap min
    markSort(array,indx,pFilRow);
    //print the array
    cout<<"Display Sorting Array:"<<endl;
    prntAry(array,indx,pFilRow,perLine);
    //print the original one
    cout<<"Display Original Array After Sorting:"<<endl;
    prntAry(array,pFilRow,perLine);
    //Exit stage right
    return 0;
}
//print perLine col for the array output by row
void prntAry(const int a[],int n,int perLine) {
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
    cout<<endl;
}

void markSort(const int a[],int indx[],int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[indx[i]]>a[indx[j]]) swap(indx[i],indx[j]);     
        } 
    }
}

void swap(int &a,int &b) {
    //in place swap using logical exclusive or's
    a=a^b;
    b=a^b;
    a=a^b;
}

//print perLine col for the array output by row
void prntAry(const int a[],const int indx[],int n,int perLine) {
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[indx[i]]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
    cout<<endl;
}

//Randomly fill the array which makes it sorted
void filAray(int a[],int indx[],int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
        indx[i]=i;
    }
}
