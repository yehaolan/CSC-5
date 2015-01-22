/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 21, 2015, 10:21 PM
 * Purpose:Homework assignment4(Savitch_8thEd_Chap4_ProgProj2)
 * Modify based from program project1 in chapter4
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const float LPRGALN=0.264179;//gallons per liter

//Function Prototypes
float calMPG();

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float mpg1,mpg2;//mile per gallon
    //introduce the program
    cout<<"This program can calculate which car "<<endl;
    cout<<"has the best fuel efficiency in two cars"<<endl;
    cout<<"First input the first car, then the second car"<<endl<<endl;
    //calculate the result with function
    mpg1=calMPG();
    mpg2=calMPG();
    //Output the result
    cout<<setprecision(2)<<fixed;
    cout<<"With 1 gallon gasoline, first car can travel "<<mpg1<<" miles"<<endl;
    cout<<"With 1 gallon gasoline, second car can travel "<<mpg2<<" miles"<<endl;
    cout<<endl;
    if(mpg1==mpg2)
        cout<<"They have the same fuel efficiency"<<endl;
    else if(mpg1>mpg2)
        cout<<"The first car has the better fuel efficiency"<<endl;
    else
        cout<<"The second car has the better fuel efficiency"<<endl;
    
    //Exit stage right
    return 0;
}

float calMPG() {
    //declare variables
    float gsl, //gasoline of the car
          dis; //distance
    //Prompt user for liters of gasoline of car and the distance
    do {    
        cout<<"Input the number of liters of gasoline consumed by your car"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>gsl;
        if(gsl<=0)
            cout<<"Invalid input"<<endl;
    }while(gsl<=0);
    do {
        cout<<"Input the distance traveled by your car(in miles)"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>dis;
    }while(dis<=0);
    return dis*LPRGALN/gsl;
}

