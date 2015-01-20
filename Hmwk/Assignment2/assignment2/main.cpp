/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 19, 2015, 5:07 PM
 * Purpose:assignment2(nine program)
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream> //File I/O
#include <ctime> //Time Functions
using namespace std;

//User Libraries

//Global Constants
const char CONVPT = 100;
const float YN_P_DOL = 119.54;  //Yen per dollar 
const float ER_P_DOL = 0.85;    //Euros per dollar
const float CMTNONS = 3.527392e4f;//conversion from Metric Tons to Ounces
const float CNVLBGM= 453.6;
const float PYINCS = 0.076;//pay increase percent

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char pg;//which program user choose
    do {
        //display the menu and prompt user for opening program 
        cout<<"---------------Assignment 2---------------"<<endl;
        cout<<"***************Program Menu***************"<<endl;
        cout<<"1.Celsius to Fahrenheit"<<endl;
        cout<<"2.Interest Earned"<<endl;
        cout<<"3.Currency"<<endl;
        cout<<"4.Stock Transaction Program"<<endl;
        cout<<"5.Metric conversion"<<endl;
        cout<<"6.Sweetener Research"<<endl;
        cout<<"7.Retroactive Pay"<<endl;
        cout<<"8.Meeting Attending"<<endl;
        cout<<"9.Babylonian Program"<<endl;
        cout<<"0.End the program"<<endl<<endl;
        cout<<"Which program you want to open"<<endl;
        cin>>pg;

        switch(pg) {
            case '0':
                cout<<"This is the end of the program"<<endl;
                break;
            case '1': {
                //Gaddis_7thEd_Chap3_ProgChal10
                //declare variable
                short cls;//Celsius Temperature
                float fhe;//Fahrenheit temperatures

                //introduce the program
                cout << "This program converts Celsius temperatures ";
                cout << "to Fahrenheit temperatures." << endl;

                //Prompt user for Celsius temperatures
                cout << "Input Celsius temperatures.\n";
                cout << "Please input an integer between 0 and 100.\n";
                cin >> cls;

                //calculate the results
                fhe=9.0f/5*cls+32;

                //formatted output the result
                cout << setprecision(1) << fixed;
                cout << "The temperature you entered " ;
                cout << "in Fahrenheit is "<< fhe << " degrees.\n";
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '2': {
                //Gaddis_7thEd_Chap3_ProgChal16
                //declare variables
                float intRate, //interest rate
                      prnp,    //principal
                      intrst,  //interest
                      saving;  //amount in savings
                short tmCmp;   //the number of times that the interest is compounded

                //Prompt user for interest rate,time compounded,and principal
                cout << "Interest Rate: " << endl;
                cout << "Please input a number in percent.\n";
                cin >> intRate;
                cout << "The times compounded: " << endl;
                cout << "Please input an integer greater than 0" <<endl;
                cin >> tmCmp;
                cout << "Principal(dollar): ";
                cout << "Please input a number greater than 1." <<endl;
                cin >> prnp;

                //calculate the results
                saving = prnp*pow((1+intRate/tmCmp/CONVPT),tmCmp);
                intrst = saving - prnp;

                //Formatted output the results
                cout << setprecision(2) << fixed;
                cout << "Interest Rate:       " << setw(7) << intRate << "%" << endl;
                cout << "Times Compounded:    " << setw(7) << tmCmp << endl;
                cout << "Principal:          $" << setw(7) << prnp << endl;
                cout << "Interest:           $" << setw(7) << intrst << endl;
                cout << "Amount in Savings:  $" << setw(7) << saving << endl;
                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '3': {
                //Gaddis_7thEd_Chap3_ProgChal11
                //declare variables and initialize
                float bcToDlr=232.8;    //Jan 13th,2015 10:17am
                float erToDlr=0.849381; //same date
                float ynToDlr=118.03;   //Same date
                float bitcoin,dollars,euros,yen;

                //Input the number of bitcoin and then convert
                cout << "Input the number of bitcoin " << endl;
                cout << "You wish to purchase." << endl;
                cin >> bitcoin;
                //convert to all the currencies
                dollars = bcToDlr*bitcoin;
                euros = erToDlr*dollars;
                yen = ynToDlr*dollars;
                //Output the results

                cout<<setprecision(2)<<fixed;
                cout << bitcoin << " = " << dollars << "(dollars)" << endl;
                cout << bitcoin << " = " << euros << "(euros)" << endl;
                cout << bitcoin << " = " << yen << "(yen)" << endl;
                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '4': {
                //Gaddis_7thEd_Chap3_ProgChal21
                //declare variables
                char cmsPer = 2;//The percentage of commission for transaction
                short shrNum = 1000;//the amount of shares that Joe bought      
                float byPrShr = 32.87,// the price of each share when buy
                      sdPrshr = 33.92,// the price of each share when sold
                      cmsBuy,//the amount of commission when buy
                      cmsSod,//the amount of commission when sold
                      prf,   //profit after selling stock and paying two commissions
                      stkSod,//the amount of money when he sold the stock
                      stkPrc;//the amount of money when he bought the stock

                //calculate the result
                stkPrc = shrNum*byPrShr;            //how much he paid for stock
                cmsBuy = stkPrc*cmsPer/CONVPT;      //how much he paid for cms when buy stock
                stkSod = shrNum*sdPrshr;            //how much he sold for stock
                cmsSod = stkSod*cmsPer/CONVPT;      //how much he paid for cms when sold stock
                prf = stkSod-stkPrc-cmsBuy-cmsSod;  //profit

                //output the results
                cout << setprecision(2) <<fixed;
                cout << "The amount of money Joe paid for the stock is $" << stkPrc << endl;
                cout << "The amount of commission Joe paid his broker" << endl;
                cout << "when he bought the stock is $" << cmsBuy <<endl;
                cout << "The amount that Joe sold the stock for is $" << stkSod <<endl;
                cout << "The amount of commission Joe paid his broker" << endl;
                cout << "when he sold the stock is $" << cmsSod << endl;
                cout << "the amount of profit that Joe made after selling his stock" << endl;
                cout << "and paying the two commissions to his broker is "<<prf <<" dollars.\n";
                if(prf>=0)
                    cout << "That means he won " << abs(prf) << " dollars.\n";
                else 
                    cout << "That means he lost " << abs(prf) << " dollars.\n";

                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '5': {
                //Savitch_8thEd_Chap2_ProgProj1
                //declare variables
                float wtPackOz,  //weight of cereal contents in ounces
                      wtPackTn,  //weight of cereal contents in tons
                      nPackTn;   //number of cereal boxes in a metric ton
                char answer;
                //Prompt user for cereal weight
                cout << "Input the number ounces on the cereal" << endl;
                cout << "box to convert to metric tons." << endl;
                cout << "Format is float ddd.ddd(onuces)" << endl;
                cin >> wtPackOz;
                //calculate the results
                wtPackTn = wtPackOz/CMTNONS;
                nPackTn = 1/wtPackTn;
                //Output the results
                cout << "Weight of cereal box is " << wtPackTn << " Metric Tons." << endl;
                cout << "Number of cereal box in a metric ton => " << nPackTn << endl;

                //Ask if user would like to repeat the calculation
                cout << "Would you like to repeat the calculation?" <<endl;
                cout << "Or make a new calculation?" << endl;
                cout << "Type Y for yes and N for no." << endl;
                cin >> answer;

                if(answer=='Y'||answer == 'y') {
                    //Prompt user for cereal weight
                    cout << "Input the number ounces on the cereal" << endl;
                    cout << "box to convert to metric tons." << endl;
                    cout << "Format is float ddd.ddd(onuces)" << endl;
                    cin >> wtPackOz;
                    //calculate the results
                    wtPackTn = wtPackOz/CMTNONS;
                    nPackTn = 1/wtPackTn;
                    //Output the results
                    cout << "Weight of cereal box is " << wtPackTn << " Metric Tons." << endl;
                    cout << "Number of cereal box in a metric ton => " << nPackTn << endl;
                }

                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '6': {
                //Savitch_8thEd_Chap2_ProgProj2
                //declare variables
                const float CONC = 1e-3f;//sweetener concentration
                float wtCoke=3.5e2f;//weight of coke in grams
                float kMouse = 5.0f,//quantity of sweetener that kills a mouse
                      wtMouse=3.5e1f,//weight of mouse that kills a mouse in grams
                      kPer,
                      wtDsPer;
                int nCans;
                //Input the desire weight of person
                cout << "Input your desire weight in lbs" << endl;
                cout << "Format the input as a float" << endl;
                cin >> wtDsPer;
                wtDsPer*=CNVLBGM;
                //calculation
                kPer = kMouse/wtMouse*wtDsPer;
                nCans = kPer/wtCoke/CONC;
                //Output the limit of what you can drink
                cout << "Number of cans of diet coke that will kill you = " << nCans << endl;

                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '7': {
                //Savitch_8thEd_Chap2_ProgProj3
                //declare variables
                int preAnSlr; //previous annual salary
                float rtrPay,//the amount of retroactive pay due the employee
                      nwAnSlr,//the new annual salary
                      nwMnSlr;//the new monthly salary
                char answ;//the answer of whether run this program again


                do {
                    //Prompt user for previous annual salary
                    cout << "Your previous annual salary(dollar): " << endl;
                    cout << "Please input a positive integer." << endl;
                    cin >> preAnSlr;

                    //calculate the results
                    rtrPay = PYINCS*preAnSlr;
                    nwAnSlr = preAnSlr + rtrPay;
                    nwMnSlr = nwAnSlr/12;

                    //Formatted output the results
                    cout << setprecision(2) << fixed;
                    cout << "Your retroactive pay is $" << rtrPay << endl;
                    cout << "Your new annual salary is $" << nwAnSlr << endl;
                    cout << "Your new monthly salary is $" << nwMnSlr << endl;

                    //Ask if user want to repeat the program
                    cout << "Would you like to repeat this program?" << endl;
                    cout << "Type Y for yes and N for no." << endl;
                    cin >> answ;
                } while(answ=='Y'||answ=='y'); //when answer is 'y' or 'Y',run it again

                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '8': {
                //Savitch_8thEd_Chap2_ProgProj6
                //declare variables
                unsigned short capcty, //the capacity of the meeting room
                               attend; //the number of people attending meeting
                short difenc; // difference between capacity and the number of attending
                char answr;     //answer for whether repeat program
                //introduce the program
                cout << "This program determines whether a meeting room is in violation of " << endl;
                cout << "fire law regulations regarding the maximum room capacity."  <<endl;

                do {
                    //Prompt user for capacity and attending people
                    cout << endl;
                    cout << "Input the meeting room capacity:" << endl;
                    cout << "Please input a positive integer." << endl;
                    cin >> capcty;
                    cout << "Input the number of people attending the meeting:" << endl;
                    cout << "Please input a positive integer." << endl;
                    cin >> attend;

                    //calculate the difference capacity and the number of attending
                    difenc = capcty - attend;

                    //determine whether the attending number is over capacity,and output the result
                    if(difenc>=0) {
                        cout << "It is legal to hold the meeting." << endl;
                        cout << difenc << " additional people may legal attend." << endl;
                    } 
                    else {
                        cout << "The meeting cannot be held as planned due to fire regulations." << endl;
                        cout << (-difenc) << " people must be excluded in order ";
                        cout << "to meet the fire regulations." << endl;
                    }
                    //Ask if repeat the program
                    cout << endl;
                    cout << "Would you like to repeat this program?" << endl;
                    cout << "Type Y for yes and N for no." << endl;
                    cin >> answr;
                } while(answr=='Y' || answr=='y');

                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }    
            case '9': {
                //Savitch_8thEd_Chap2_ProgProj10
                //declare variables
                float number,guess,r;
                short count = 0;
                //input a number
                cout << "Input a number to estimate it's square root"<<endl;
                cout << "The format fill be a float positive float" <<endl;
                cin >> number;
                //first pass
                guess = number/2;
                do {
                    r = number/guess;
                    guess = (guess+r)/2;
                    count++;
                    //Output the first pass
                    cout << "Loop "<< count <<"  -> " << guess << endl;
                //}while(guess!=r); //My preferred technique
                }while(abs(guess-r)>0.01);
                
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            default:
                cout<<"Invalid input"<<endl;
                cout<<"Choose again"<<endl;
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
        }
    }while(pg!='0');
   
    //Exit stage right
    return 0;
}

