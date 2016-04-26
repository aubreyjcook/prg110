/* pseudocode
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream outputMonthFile;

	get user input for month
	validate the month number
	switch statement output to file for month name
	output header for month file
	calculate the starting day of the month
	// this is based on the fact that 01/01/2015 was a Thursday, the actual start day of the given month is found by calculating each given start day of the different months in a function,
	// and selecting the given month based on the user input in an if statement that calls the function at the month number

	print to the file the correct month calendar

}
pseudocode */

#include <iostream>
#include <fstream>

using namespace std;

int getStartingDay(int);

int main() {
    int month;

    cout <<"This program prints a calender for a given month in 2015 to the current directory called 'calenderMonth.txt'\n" "Enter the month for the calender as a number: ";
    cin >> month;
    while (month <= 0 || month > 12) { // input validation for valid months between 1 - 12
        cout << "Try again.\nEnter a number for the month between 1-12: ";
        cin >> month;
    }

    cout << "Okay, let me fetch the month and days on the calender\n";

    ofstream monthCalender;
    monthCalender.open("monthCalender.txt");

    if (monthCalender) // this if statement only checks to make sure the file opened, the else statement at the end displays an error
    {
    monthCalender<<endl;
    switch(month) { // this switch statement prints the header with the current month and the year in the calender file

        case 1:
        monthCalender << "                        " << "JANUARY" << " 2015";
        break;
        case 2:
        monthCalender << "                        " << "FEBRUARY" << " 2015";
        break;
        case 3:
        monthCalender << "                        " << "MARCH" << " 2015";
        break;
        case 4:
        monthCalender << "                        " << "APRIL" << " 2015";
        break;
        case 5:
        monthCalender << "                        " << "MAY" << " 2015";
        break;
        case 6:
        monthCalender << "                        " << "JUNE" << " 2015";
        break;
        case 7:
        monthCalender << "                        " << "JULY" << " 2015";
        break;
        case 8:
        monthCalender << "                        " << "AUGUST" << " 2015";
        break;
        case 9:
        monthCalender << "                        " << "SEPTEMBER" << " 2015";
        break;
        case 10:
        monthCalender << "                        " << "OCTOBER" << " 2015";
        break;
        case 11:
        monthCalender << "                        " << "NOVEMBER" << " 2015";
        break;
        case 12:
        monthCalender << "                        " << "DECEMBER" << " 2015";
        break;
    }

    monthCalender << endl  // this prints the header for the days of the week to the calender file
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   S   |   M   |   T   |   W   |   T   |   F   |   S   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";

    switch(getStartingDay(month)) { // this switch statement places the number of empty spaces on the calender before the starting day
        case 1:
        monthCalender<<endl<<"|       |";
        break;
        case 2:
        monthCalender<<endl<<"|       |       |";
        break;
        case 3:
        monthCalender<<endl<<"|       |       |       |";
        break;
        case 4:
        monthCalender<<endl<<"|       |       |       |       |";
        break;
        case 5:
        monthCalender<<endl<<"|       |       |       |       |       |";
        break;
        case 6:
        monthCalender<<endl<<"|       |       |       |       |       |       |";
        break;
        case 7:
        monthCalender<<endl<<"|";
        break;
    }

    switch(month){ // this switch statement prints the full calender days

        case 1:
        monthCalender      << "   1   |   2   |   3   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   4   |   5   |   6   |   7   |   8   |   9   |  10   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  11   |  12   |  13   |  14   |  15   |  16   |  17   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  18   |  19   |  20   |  21   |  22   |  23   |  24   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  25   |  26   |  27   |  28   |  29   |  30   |  31   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 2:
        monthCalender      << "   1   |   2   |   3   |   4   |   5   |   6   |   7   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   8   |   9   |  10   |  11   |  12   |  13   |  14   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  15   |  16   |  17   |  18   |  19   |  20   |  21   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  22   |  23   |  24   |  25   |  26   |  27   |  28   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 3:
        monthCalender      << "   1   |   2   |   3   |   4   |   5   |   6   |   7   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   8   |   9   |  10   |  11   |  12   |  13   |  14   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  15   |  16   |  17   |  18   |  19   |  20   |  21   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  22   |  23   |  24   |  25   |  26   |  27   |  28   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  29   |  30   |  31   |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 4:
        monthCalender      << "   1   |   2   |   3   |   4   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   5   |   6   |   7   |   8   |   9   |  10   |  11   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  12   |  13   |  14   |  15   |  16   |  17   |  18   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  19   |  20   |  21   |  22   |  23   |  24   |  26   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  27   |  30   |       |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 5:
        monthCalender      << "   1   |   2   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   3   |   4   |   5   |   6   |   7   |   8   |   9   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  10   |  11   |  12   |  13   |  14   |  15   |  16   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  17   |  18   |  19   |  20   |  21   |  22   |  23   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  24   |  25   |  26   |  27   |  28   |  29   |  30   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  31   |       |       |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 6:
        monthCalender      << "   1   |   2   |   3   |   4   |   5   |   6   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   7   |   8   |   9   |  10   |  11   |  12   |  13   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  14   |  15   |  16   |  17   |  18   |  19   |  20   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  21   |  22   |  23   |  24   |  25   |  26   |  27   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  28   |  29   |  30   |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 7:
        monthCalender      << "   1   |   2   |   3   |   4   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   5   |   6   |   7   |   8   |   9   |  10   |  11   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  12   |  13   |  14   |  15   |  16   |  17   |  18   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  19   |  20   |  21   |  22   |  23   |  24   |  26   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  27   |  30   |  31   |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 8:
        monthCalender      << "   1   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   2   |   3   |   4   |   5   |   6   |   7   |   8   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   9   |  10   |  11   |  12   |  13   |  14   |  15   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  16   |  17   |  18   |  19   |  20   |  21   |  22   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  23   |  24   |  25   |  26   |  27   |  28   |  29   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  30   |  31   |       |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 9:
        monthCalender      << "   1   |   2   |   3   |   4   |   5   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   6   |   7   |   8   |   9   |  10   |  11   |  12   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  13   |  14   |  15   |  16   |  17   |  18   |  19   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  20   |  21   |  22   |  23   |  24   |  25   |  26   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  27   |  28   |  29   |  30   |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 10:
        monthCalender      << "   1   |   2   |   3   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   4   |   5   |   6   |   7   |   8   |   9   |  10   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  11   |  12   |  13   |  14   |  15   |  16   |  17   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  18   |  19   |  20   |  21   |  22   |  23   |  24   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  25   |  26   |  27   |  28   |  29   |  30   |  31   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 11:
        monthCalender      << "   1   |   2   |   3   |   4   |   5   |   6   |   7   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   8   |   9   |  10   |  11   |  12   |  13   |  14   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  15   |  16   |  17   |  18   |  19   |  20   |  21   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  22   |  23   |  24   |  25   |  26   |  27   |  28   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  29   |  30   |       |       |       |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
        case 12:
        monthCalender      << "   1   |   2   |   3   |   4   |   5   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|   6   |   7   |   8   |   9   |  10   |  11   |  12   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  13   |  14   |  15   |  16   |  17   |  18   |  19   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  20   |  21   |  22   |  23   |  24   |  25   |  26   |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|\n"
                           << "|  27   |  28   |  29   |  30   |  31   |       |       |\n"
                           << "|-------|-------|-------|-------|-------|-------|-------|";
        break;
    } }
    else { cout << "Error: File failed to open.\nCheck to see there is no file named 'calenderMonth' in the directory of the source file."; return 0;}

    cout << "Done. Check the directory this program ran in for the calender file.\n";
    cout << getStartingDay(month);
    monthCalender.close();
    return 0;
}

int getStartingDay(int monthGiven){
    int totalDays;
    switch (monthGiven) {
        case 1:
        totalDays = 4;
        break;
        case 2:
        totalDays = 4 + 31;
        break;
        case 3:
        totalDays = 4 + 31 + 28;
        break;
        case 4:
        totalDays = 4 + 31 + 28 + 31;
        break;
        case 5:
        totalDays = 4 + 31 + 28 + 31 + 30;
        break;
        case 6:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31;
        break;
        case 7:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31 + 30;
        break;
        case 8:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31 + 30 + 31;
        break;
        case 9:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
        case 10:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
        case 11:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
        case 12:
        totalDays = 4 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;

    }

    while (totalDays > 7) {
        totalDays = totalDays - 7;
    }
    return totalDays;
}
