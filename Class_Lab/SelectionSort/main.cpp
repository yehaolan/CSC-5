/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on Feb 3, 2015, 10:29 AM
 * Purpose:Developing selection sort
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
int minLst(int,int[],int);//find the min in the list
void selSort(int[],int);//with swap function
void selcSrt(int[],int);//without swap function

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
    selcSrt(array,pFilRow);
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
void selSort(int a[],int n) {
    //swap as we go down the list
    for(int i=0;i<n-1;i++) {
        int indx=minLst(i,a,n);
        if(i!=indx) swap(a[i],a[indx]);
    }
    
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
int minLst(int pos,int a[],int n) {
    //declare and set the min
    int min=a[pos],indx=pos;
    //Loop and find the min in the list
    for(int i=pos+1;i<n;i++) {
        if(a[i]<min) {
            min=a[i];
            indx=i;
        }
    }
    return indx;
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
