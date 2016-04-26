#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // declaring variables
    char userPlan;
    int minutesUsed;
    float totalOwed;
    float totalOwedAlt;
    string currentMonth;

    // program

    // user input
    cout << "What phone service package have you selected?\n" << endl
         << "Package A: For $39.99 per month 450 minutes are provided. Additional minutes are $0.45 per minute.\n" << endl
         << "Package B: For $59.99 per month 900 minutes are provided. Additional minutes are $0.40 per minute.\n" << endl
         << "Package C: For $69.99 per month unlimited minutes provided.\n" << endl;
    cin >> userPlan;

	if (userPlan == 'a' || userPlan == 'A' || userPlan == 'b' || userPlan == 'B') {
    cout << "How many minutes were used in the month?" << endl;
    cin >> minutesUsed;
    }

    cout << "Enter the month by name" << endl;
    cin >> currentMonth;

    // input validation of minutesUsed
    if(std::string(currentMonth) == "january" ||
       std::string(currentMonth) == "January" ||
       std::string(currentMonth) == "march" ||
       std::string(currentMonth) == "March" ||
       std::string(currentMonth) == "may" ||
       std::string(currentMonth) == "May" ||
       std::string(currentMonth) == "july" ||
       std::string(currentMonth) == "July" ||
       std::string(currentMonth) == "august" ||
       std::string(currentMonth) == "August" ||
       std::string(currentMonth) == "october" ||
       std::string(currentMonth) == "October" ||
       std::string(currentMonth) == "december" ||
       std::string(currentMonth) == "December"
       ){ if (minutesUsed > 60 * 744 || minutesUsed < 0){ cout << "You did not enter a valid number of minutes!" << endl;} }

    else if(std::string(currentMonth) == "april" ||
       std::string(currentMonth) == "April" ||
       std::string(currentMonth) == "june" ||
       std::string(currentMonth) == "June" ||
       std::string(currentMonth) == "september" ||
       std::string(currentMonth) == "September" ||
       std::string(currentMonth) == "november" ||
       std::string(currentMonth) == "November"
       ) { if (minutesUsed > 60 * 720 || minutesUsed < 0){ cout << "You did not enter a valid number of minutes!" << endl;} }

    else if(std::string(currentMonth) == "february" ||
       std::string(currentMonth) == "February"
       ) { if (minutesUsed > 60 * 672 || minutesUsed < 0){ cout << "You did not enter a valid number of minutes!" << endl;} }

    else{ cout << "You did not enter a valid month!" << endl; }

    // input validation of userPlan
    switch(userPlan) {
    case 'a':
	case 'A':
	totalOwed = 39.99;
		if(minutesUsed > 450) { totalOwed = totalOwed + ((minutesUsed - 450) * .45); }
		break;

    case 'b':
	case 'B':
	totalOwed = 59.99;
		if (minutesUsed > 900) { totalOwed = totalOwed + ((minutesUsed - 900) * .40); }
		break;

    case 'c':
	case 'C':
	totalOwed = 69.99;
        break;

	default: cout << "You did not enter a valid plan letter!" << endl;
	}

	// this prints the total owed
    cout << "The total owed for this month's bill is: $" << setprecision(2) << fixed << left << totalOwed << endl << "\n";

    // calculating the amount saved for different plans and printing the amounts
    switch(userPlan){
    case 'a':
	case 'A':
        totalOwedAlt = 59.99;
        if(minutesUsed > 900) { totalOwedAlt = totalOwedAlt +((minutesUsed - 900)) *.45; }
        if(totalOwedAlt < 0) { totalOwedAlt = 59.99; }
        if(totalOwedAlt < totalOwed) {
        cout << "The total you would save from your bill if you switched to Package B is: $"
        << setprecision(2) << fixed << left << totalOwed - totalOwedAlt << endl;
        totalOwedAlt = 69.99;
        if (totalOwedAlt < totalOwed) {
        cout << "The total you would save from your bill if you switched to Package C is: $"
        << setprecision(2) << fixed << left << totalOwed - totalOwedAlt << endl;
        }
        break;

    case 'b':
	case 'B':
        totalOwedAlt = 69.99;
        cout << "The total you would save from your bill if you switched to Package C is: $"
        << setprecision(2) << fixed << left << totalOwed - totalOwedAlt << endl;
        }
        break;
    }
    return 0;
}
