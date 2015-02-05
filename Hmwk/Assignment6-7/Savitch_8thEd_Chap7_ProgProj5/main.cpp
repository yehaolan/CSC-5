/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 4, 2015, 10:39 AM
 * Purpose:Savitch_8thEd_Chap7_ProgProj5
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries

//Global constants

//Function Prototypes
void dspOcur(int[],int);
void bubSort(int [],int);
void fndOcur(int[],int[],int[],int);

//Execution Begins here
int main(int argc, char** argv) {
    //declare variables
    int choice;
    do {
        cout<<"Which way you prefer to read a list of integer?"<<endl;
        cout<<"1. File"<<endl;
        cout<<"2. Keyboard"<<endl;
        cin>>choice;
        if(choice<1||choice>2)
            cout<<"Invalid input"<<endl;
    } while(choice<1||choice>2);
    
    if(choice==1){ //if choose file
        //set seed for random number
        srand(static_cast<unsigned int>(time(0)));
        //declare variables
        const int SIZE=20;
        char name[30];//char array for file name
        int num;
        int array[SIZE]={};
        //file object
        ofstream output;
        ifstream input;
        //get file name
        cout<<"Input the name of file you would like to open(including suffix)"<<endl;
        cin>>name;
        output.open(name);
        //randomly output the number to the file
        for(int i=0;i<SIZE;i++) {
            output<<rand()%15+1<<endl;
        }
        output.close();
        input.open(name);
        //copy the number to the array
        for(int i=0;input>>num;i++) {
            array[i]=num;
        }
        dspOcur(array,SIZE);//display the number of occurrences of inputted number
        input.close();
    } else {    //choose keyboard
        const int SIZE=20;
        int array[SIZE];
        //Prompt user for 20 integer
        cout<<"Please input 20 integer to the array"<<endl;
        for(int i=0;i<SIZE;i++) {
            cout<<(i+1)<<": ";
            cin>>array[i];
        }
        dspOcur(array,SIZE);//display the number of occurrences of inputted number
    }
    //Exit stage right
    return 0;
}

void dspOcur(int a[],int size) {
    const int SIZE=20;
    int occNum[SIZE]={};//the array storing the number occurred
    int fnd[SIZE]={};//record the number of occurrence
    int count=0;//count how many number occurred
    //get all numbers occur in the array
    for(int i=0;i<SIZE;i++) {
        bool inside=false;
        for(int j=0;j<SIZE;j++){
            if(a[i]==occNum[j]) inside=true;
        }
        if(!inside) occNum[count++]=a[i];
    }
    //display all element of array
    cout<<"These numbers are in the array:"<<endl;
    for(int i=0;i<SIZE;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //sort the occur number from big -> small
    bubSort(occNum,count); 
    cout<<endl;
    //find out the number of occurring of occur number
    fndOcur(occNum,fnd,a,count);
    //display the results
    cout<<"  N   "<<" Count "<<endl;
    for(int i=0;i<count;i++) {
        cout<<setw(3)<<occNum[i]<<setw(6)<<fnd[i]<<endl;
    }
    int totOcc=0;
    for(int i=0;i<count;i++){
        totOcc+=fnd[i];
    }
    if(totOcc!=20)
        cout<<setw(3)<<0<<setw(6)<<(20-totOcc)<<endl;
    
    cout<<endl;
}

void bubSort(int a[],int size) {
    bool swap;
    do {
        swap=false;
        for(int i=0;i<size-1;i++) {
            if(a[i]<a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

void fndOcur(int on[],int fnd[],int a[],int count) { //on[]means occur numbers
    const int SIZE=20;
    //record the number of occurring of occur number
    for(int i=0;i<count;i++) {
        int count=0;
        for(int j=0;j<SIZE;j++) {
            if(on[i]==a[j]) count++;
        }
        fnd[i]=count;
    }
}
