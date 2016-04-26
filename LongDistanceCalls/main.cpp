/* pseudocode

//variables
float startTime // user input
int totalMinutes // user input
float callCharge

//program

//confirming call time input validation
 output statement: "What is the starting time of your call? Please enter in the format: HH.MM where H is the number of hours, and M is the number of minutes."
	input = startTime

	if startTime - static-cast<int>((n - static-cast<int>(n) * 100) > 60 {
				output statement: "You entered an invalid time! There are too many minutes, please try again and enter a value between 0 - 59"
end program
			      }

	else if startTime > 23.59 {
				output statement: "You entered more time than there is in a day! Please try again and enter the time correctly."
end program
				  }

//calculating minutes and charge of the call
	output statement: "How many minutes long was your call?"
	input totalMinutes
	output statement: "Calculating the charge of your call..."

	if startTime < 7.00 {
			    totalMinutes * 0.12 = callCharge
			    }

	else if startTime > 7.00 && < 19.00 {
					    totalMinutes * 0.55 = callCharge
					    }

	else if startTime > 19.00 && < 23.59.00 {
					    totalMinutes * 0.35 = callCharge
					    }

//displaying the charge
	output statement: "The total charge for your call is: $" << showpoint(2) << left << fixed << callCharge */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // variables
float startTime;
float totalMinutes;
float callCharge;

    //program

    // input validation
    cout << "What is the starting time of your call?" << endl << "Please enter in the format: HH.MM where H is the number of hours, and M is the number of minutes." << endl;
    cin >> startTime;

    if (startTime - static_cast<int>(startTime) > .60 ) {
        cout << "You entered an invalid time! There are too many minutes, please try again and enter a value between 0 - 59";
                                      }
    else if(startTime > 24.00){
        cout << "You entered more time than there is in a day! Please try again and enter the time correctly.";
    }

    // calculating charge

    cout << "How many minutes long was your call?" << endl;
    cin >> totalMinutes;

    cout << "Calculating the charge of your call..." << endl << '\n';

    if (startTime <= 6.59){
			    callCharge = totalMinutes * 0.12;
			    }

	else if (startTime > 6.59 && startTime <= 19.00) {
					    callCharge = totalMinutes * 0.55;
					    }

	else if (startTime > 19.00 && startTime <= 24.00) {
					    callCharge = totalMinutes * 0.35;
					    }

    cout << "The total charge for your call is: $" << setprecision(2) << fixed << left << callCharge;

    return 0;
}
