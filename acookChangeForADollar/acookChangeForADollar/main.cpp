/* peusdocode

// variables
constant pennyValue = 1
constant nickelValue = 5
constant dimeValue = 10
constant quarterValue = 25

int penniesEntered // user input
int nickelsEntered // user input
int dimesEntered // user input
int quartersEntered // user input
int sumTotal

// program
output statement: "Enter the necessary change to equal one dollar and you win the game"
output statement: "Enter the number of pennies"
	input: penniesEntered

output statement: "Enter the number of nickels"
	input: nickelsEntered
	nickelsEntered * nickelValue = nickelsEntered

output statement: "Enter the number of dimes"
	input: dimesEntered
	dimesEntered * dimeValue = dimesEntered

output statement: "Enter the number of quarters"
	input: quartersEntered
	quartersEntered * quarterValue = quartersEntered

output statement: "Calculating your change..."
	penniesEntered + nickelsEntered + dimesEntered + quartersEntered = sumTotal

if sumTotal = 100 {
	output statement: "You entered exactly one dollar, good!"
		  }
else if sumTotal > 100 {
	output statement: "Sorry, you did not enter the exact change for a dollar, your change is more than $1.00 please try again."
     }
else if sumTotal < 100 {
	output statement: "Sorry, you did not enter the exact change for a dollar, your change is less than $1.00 please try again."
     }

*/

#include <iostream>

using namespace std;

int main()
{
    // declaring variables
    int penniesEntered;
    int nickelsEntered;
    int dimesEntered;
    int quartersEntered;
    int sumTotal;

    // program

    // collecting user input
    cout << "Enter the necessary change to equal one dollar and you win the game \n" << endl
         << "Enter the Number of pennies: " << endl;
    cin >> penniesEntered;

    cout << "Enter the number of nickels: " << endl;
    cin >> nickelsEntered;
    nickelsEntered = nickelsEntered * 5;

    cout << "Enter the number of dimes: " << endl;
    cin >> dimesEntered;
    dimesEntered = dimesEntered * 10;

    cout << "Enter the number of quarters: " << endl;
    cin >> quartersEntered;
    quartersEntered = quartersEntered * 25;

    // calculating
    cout << "Calculating your change... \n" << endl;
    sumTotal = penniesEntered + nickelsEntered + dimesEntered + quartersEntered;

    // result and input validation
    if (sumTotal == 100) {
            cout << "You entered exactly one dollar, good!";
    }

    else if (sumTotal > 100) {
        cout << "Sorry, you did not enter the exact change for a dollar, your change is more than $1.00, please try again.";
    }

    else if (sumTotal < 100) {
        cout << "Sorry, you did not enter the exact change for a dollar, your change is less than $1.00, please try again.";
    }

    return 0;
}
