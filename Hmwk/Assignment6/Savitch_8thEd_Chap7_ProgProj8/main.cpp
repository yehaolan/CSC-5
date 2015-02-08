/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 7, 2015, 5:06 PM
 * Purpose: Savitch_8thEd_Chap7_ProgProj8
 */

//system Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void getOcc(const char [],char [],const int,int &);
void gtTimes(const char [],const int,int [],const char [],int);
void sort(char [],int,int []);
//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE=100;
    char line[SIZE];
    char occed[SIZE];
    int occTm[SIZE];
    int count=0;
    bool corr;
    //Introduce the program
    cout<<"This program can find out the number of "<<endl;
    cout<<"occurrence of letter in a sentence"<<endl;
    //Prompt user for a lowercase sentence with period ending
    do {
        corr=true;
        cout<<"Input a sentence which is ended with period"<<endl;
        cout<<"Note:Only lowercase letter can be accepted"<<endl;
        cin.getline(line,SIZE);
        cout<<endl;
        cout<<strlen(line)<<endl;
        if(line[strlen(line)-1]!='.') corr=false;
        for(int i=0;i<strlen(line)-1;i++) {
            if(line[i]==' ') corr=true;
            else if(line[i]<97||line[i]>122) corr=false;
        }
    }while(!corr);
    getOcc(line,occed,strlen(line)-1,count);
    
    for(int i=0;i<count;i++) {
        cout<<occed[i];
    }
    cout<<endl;
    gtTimes(occed,count,occTm,line,strlen(line)-1);
    for(int i=0;i<count;i++) {
        cout<<occTm[i];
    }
    cout<<"After sorting "<<endl;
    
    sort(occed,count,occTm);
    for(int i=0;i<count;i++) {
        cout<<occed[i];
    }
    cout<<endl;
    for(int i=0;i<count;i++) {
        cout<<occTm[i];
    }
    //Execution begins here
    return 0;
}

void getOcc(const char line[],char occ[],const int N,int &count) {
    bool repe;
    for(int i=0;i<N;i++) {
        repe=false;
        for(int j=0;j<i;j++){
            if(occ[j]==line[i]) repe=true;
        }
        if(!repe) occ[count++]=line[i];
    }
}
void gtTimes(const char occ[],const int n,int occTm[],const char line[],int len) {
    int count;
    for(int i=0;i<n;i++) {
        count=0;
        for(int j=0;j<len;j++) {
            if(occ[i]==line[j]) count++;
        }
        occTm[i]=count;
    }
}

void sort(char occ[],int n,int occTm[]) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(occTm[i]<occTm[j]) {
                int temp=occTm[i];
                occTm[i]=occTm[j];
                occTm[j]=temp;
                char tem=occ[i];
                occ[i]=occ[j];
                occ[j]=tem;
            }
        }
    }
}