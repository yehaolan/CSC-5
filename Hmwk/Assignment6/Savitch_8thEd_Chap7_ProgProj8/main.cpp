/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 7, 2015, 5:06 PM
 * Purpose: Savitch_8thEd_Chap7_ProgProj8
 */

//system Libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void getOcc(const char [],char [],const int,int &);//get occurred letters
void gtTimes(const char [],const int,int [],const char [],int);//get the number of occurrence of letter
void sort(char [],int,int []);//sort two array at a time

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE=100;
    char line[SIZE];//the sentence of input
    char occed[SIZE];//array of all occurred letter 
    int occTm[SIZE];//array of number of occurrence of letter
    int count=0;
    bool wro;//wrong
    //Introduce the program
    cout<<"This program can find out the number of "<<endl;
    cout<<"occurrence of letter in a sentence"<<endl;
    //Prompt user for a lowercase sentence with period ending
    do {
        wro=false;
        cout<<endl<<"Input a sentence which is ended with period"<<endl;
        cout<<"Note:Only lowercase letter can be accepted"<<endl;
        cin.getline(line,SIZE);
        for(int i=0;i<strlen(line)-1;i++) {
            if(line[i]==' ') wro=false;
            else if(line[i]<97||line[i]>122) wro=true;
        }
        if(line[0]==' ') wro=true;
        if(line[strlen(line)-1]!='.') wro=true;
    }while(wro);
    //get occurred letters
    getOcc(line,occed,strlen(line)-1,count);
    //get the number of occurrence of letter
    gtTimes(occed,count,occTm,line,strlen(line)-1);
    sort(occed,count,occTm);
    cout<<endl<<" Letter  "<<" Number of occurrence"<<endl;
    for(int i=0;i<count;i++) {
        cout<<"    "<<occed[i]<<"            "<<occTm[i]<<endl;
    }
    //EXit stage right
    return 0;
}
//find out all occurring letter
void getOcc(const char line[],char occ[],const int N,int &count) {
    bool repe;
    for(int i=0;i<N;i++) {
        repe=false;
        for(int j=0;j<i;j++){
            if(occ[j]==line[i]) repe=true;
            if(line[i]==' ') repe=true;
        }
        if(!repe) occ[count++]=line[i];
    }
}
//get how many times of all occurred letters occur
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

//sort the array that store occur letters and array that store number of occurrence of these letter 
void sort(char occ[],int n,int occTm[]) {
    //mark sort
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