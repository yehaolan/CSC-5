/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 8, 2015, 11:44 AM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap2_ProgChal17)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char CONVPT=100;

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short shrNum = 600,//the number of stock Kathryn bought
          payAl;//the amount paid for the stock alone
    float perSha = 21.77,//The price of per share($)
          cms,//the amount of commission
          total;//total amount paid
    char perTst = 2;//The percentage of commission for transaction
            
    //calculate the results
    payAl = shrNum*perSha;
    cms = static_cast<float>(payAl)*perTst/CONVPT;
    total = payAl + cms;
    
    //Output the result
    cout << setprecision(2)<<fixed;//set 2-digit decimal
    cout << "The amount paid for the stock alone is $" << payAl << endl;
    cout << "The amount of the commission is $" << cms <<endl;
    cout << "The total amount paid is $" << total << endl;
    
    //Exit stage right
    return 0;
}

