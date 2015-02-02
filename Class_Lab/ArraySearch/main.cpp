/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 29, 2015, 9:16 AM
 * Purpose:Utilizing partially filled array
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
int Lsearch(int,const int[],int,int);
int fndVals(int[],int,int,int[]);
void prntFnd(const int[],int,int);
int cntFnd(const int[],int,int);
//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    //declare variables and arrays
    const int SIZE=1000;
    int pFilRow=100,perLine=10;
    int array[SIZE]={};
    int found[SIZE]={};
    //fill the array,vector,2D array
    filAray(array,pFilRow);
    //print the array,vector,2D array
    prntAry(array,pFilRow,perLine);
    //test the linear search
    int val=10;
    cout<<"Where is "<<val<<" found in the array!"<<endl;
    int nTimes=fndVals(array,pFilRow,val,found);
    //print all the values found
    prntFnd(found,pFilRow,perLine);
    //How many time was the value found
    cout<<val<<" was found "<<nTimes<<"="<<cntFnd(array,pFilRow,val)<<" times"<<endl;
    //Exit stage right
    return 0;
}


int fndVals(int a[],int n,int val,int f[]) {
    //loop until you find all the elements in the array
    int indx,pos=0,count=0;
    do {
        indx=Lsearch(pos,a,n,val);
        f[count++]=indx;
        pos=indx+1;
    }while(indx>0&&indx<n);
    return --count;
}

int cntFnd(const int a[],int n,int val) {
    //loop until you find all the elements in the array
    int indx,pos=0,count=0;
    do {
        indx=Lsearch(pos,a,n,val);
        pos=indx+1;
        count++;
    }while(indx>0&&indx<n);
    return --count;
}

int Lsearch(int strt,const int a[],int end,int val) {
    //loop until you find
    for(int i=strt;i<end;i++) {
        if(val==a[i]) return i;
    }
    return -1;
}

void prntFnd(const int a[],int n,int perLine) {
    cout<<endl<<endl;
    if(a[0]==-1){
        cout<<"The value was not found"<<endl;
        cout<<endl;
        return;
    }
    cout<<"The value was found in these position"<<endl;
    for(int i=0;i<n;i++) {
        if(a[i]==-1) {
            cout<<endl;
            return;
        }
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
    cout<<endl;
}

//Random fill the array with 2-digit number
void filAray(int a[],int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
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
