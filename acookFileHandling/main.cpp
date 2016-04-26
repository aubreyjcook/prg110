#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream inputFile;
	inputFile.open("population.txt");

	ofstream outputFile;
	outputFile.open("barchart.txt");

	int populationHoldVariable; // this variable holds the data read from the file
	int currentYear = 1900; // this variable is used in the loop to display the year


	cout << "This program reads data from 'population.txt' and creates a bar chart for every 20 years starting from 1900 in the file 'barchart.txt'\n";
	// this if/else statement checks if the files opened
	if(inputFile && outputFile) {
		cout << "The files opened successfully.\n";

		// these lines print to the file the header and legend
		outputFile << "Population Growth between 1900 and 2000: \n";
		outputFile << "Legend: given year, ++ = 1000 people, - = 500+ people or more, rounded over the last 1000 people \n";

		// this loop runs until the end of the file
		while (inputFile >> populationHoldVariable) {
			outputFile << currentYear;
			currentYear += 20;

			while (populationHoldVariable > 1000) {
				populationHoldVariable -= 1000;
				outputFile << "++";
			}

			if (populationHoldVariable > 500) {
				outputFile << "-";
			}
			outputFile << endl;
		}
	}

	else {
		cout << "One or both files failed to open. Make sure population.txt is in directory.";

		return 0;
	}

	// this closes both files and ends the program
	cout << "The program is complete and the files are closing. Check directory for barchart.txt.";
	inputFile.close();
	outputFile.close();
	return 0;
}
