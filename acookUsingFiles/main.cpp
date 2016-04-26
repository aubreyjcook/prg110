#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // declaring variables
    int fileReadNumber = 0; // this variable is used in the while loop to detect what string number the loop is at, and if it is at the end of the file
    int fileNumberOfStringsTally = 0; // this variable tallies the number of strings read from the file within each iteration of the loop
    int fileStringNumbersTally = 0; // this variable tallies the actual numbers in the file
    float fileStringNumbersAverage; // this variable is used to find the floating point average of fileNumbersStringsTally and fileStringNumbersTally

    // this opens the file named "randomNumbers.txt" shared in the source file directory
    ifstream randomNumbers;
    randomNumbers.open("randomNumbers.txt");

    // this if statement checks to see if the file opened
    if (randomNumbers) {
        while(randomNumbers >> fileReadNumber){
        // this loop reads the numbers in the file one by one, adds their value to a running total, and counts each iteration of the loop to find the total number of strings in each iteration

        fileStringNumbersTally += fileReadNumber;
        fileNumberOfStringsTally++;
        }
   }

    else {
    cout << "The file failed to open.";
   }

   fileStringNumbersAverage = ((float)fileStringNumbersTally/fileNumberOfStringsTally);
   cout << "There were " << fileNumberOfStringsTally <<" number strings in the file." << endl;
   cout << "The sum of the file numbers is: " << fileStringNumbersTally << endl;
   cout << "The average of the file numbers is: " << fileStringNumbersAverage << endl;

    // this closes the file and ends the program
    randomNumbers.close();
    return 0;
}
