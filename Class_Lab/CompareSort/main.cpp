/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on Feb 3, 2015, 10:29 AM
 * Purpose:Compare sort
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
void copy(int [],int[],int);//copy
void selcSrt(int[],int);//without swap function
void bublSrt(int[],int);//without swap function
void markSort(int[],int);//mark sort in one function

//Execution begins here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //declare variables and arrays
    const int SIZE=100000;
    int pFilRow=100000,perLine=10;
    int array[SIZE]={};
    int brray[SIZE]={},crray[SIZE]={};
    int beg=time(0);
    int end=time(0);
    //fill the array
    filAray(array,pFilRow);
    copy(array,brray,pFilRow);
    copy(array,crray,pFilRow);
    //print the array
    //prntAry(array,pFilRow,perLine);
    //prntAry(brray,pFilRow,perLine);
    //prntAry(crray,pFilRow,perLine);
    //test out swap min
    int begs=time(0);
    selcSrt(array,pFilRow);
    int begb,ends; begb=ends=time(0);
    bublSrt(brray,pFilRow);
    int begm,endb; begm=endb=time(0);
    markSort(crray,pFilRow);
    int endm=time(0);
    //Print the total time
    cout<<"Bubble    sort = "<<endb-begb<<" seconds"<<endl;
    cout<<"Selection sort = "<<ends-begs<<" seconds"<<endl;
    cout<<"Mark      sort = "<<endm-begm<<" seconds"<<endl;
    //print the array
    //prntAry(array,pFilRow,perLine);
    //prntAry(brray,pFilRow,perLine);
    //prntAry(crray,pFilRow,perLine);
    //Exit stage right
    return 0;
}


void selcSrt(int a[],int n) {
    //swap as we go down the list
    for(int i=0;i<n-1;i++) {
       //declare and set the min
        int min=a[i],indx=i;
        //Loop and find the min in the list
        for(int j=i+1;j<n;j++) {
            if(a[j]<min) {
                min=a[j];
                indx=j;
            }
        } 
        if(i!=indx) {
            int temp=a[i];
            a[i]=a[indx];
            a[indx]=temp;
        }
    }
    
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
void copy(int a[],int b[],int n) {
    for(int i=0;i<n;i++) {
        b[i]=a[i];
    }
}