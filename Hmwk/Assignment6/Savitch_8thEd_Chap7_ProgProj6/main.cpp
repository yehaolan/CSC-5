/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on February 7, 2015, 12:58 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void filAray(int [],int);
void swap(int &,int &);
void prntAry(const int [],int,int);
void insrSrt(const int [],int [],int);

//Execution begins here
int main(int argc, char** argv) {
    //set the seed for random numbers
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    const int SIZE=100000;
    int pFilRow=100;
    int pl=10;//per line
    int array[SIZE]={};
    int rs[SIZE]={};//result of sorting
    //fill the array
    filAray(array,pFilRow);
    //print the array
    prntAry(array,pFilRow,pl);
    //insertion sort
    insrSrt(array,rs,pFilRow);
    //print the array
    prntAry(rs,pFilRow,pl);
    return 0;
}

//Randomly fill the array which makes it sorted
void filAray(int a[],int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
}
void swap(int &a,int &b) {
    //in place swap using logical exclusive or's
    a=a^b;
    b=a^b;
    a=a^b;
}
//print perLine col for the array output by row
void prntAry(const int a[],int n,int perLine) {
    cout<<endl<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}

void insrSrt(const int a[],int rs[],int n) {
    for(int i=0;i<n;i++) {
        rs[i]=a[i];
        for(int j=i;j>0;j--){
            if(rs[j]<rs[j-1]) swap(rs[j],rs[j-1]);
        }
    }
}