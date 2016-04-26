#include <iostream>

using namespace std;

// function prototypes
double getAccidents(string);
void findLowest(double, double, double, double, double);


int main() {
	double north, south, east, west, central;

	north = getAccidents("North");
	south = getAccidents("South");
	east = getAccidents("East");
	west = getAccidents("West");
	central = getAccidents("Central");

	findLowest(north, south, east, west, central);

	return 0;
}

double getAccidents(string cityRegion) {
	double accidents;

	cout << "Enter the number of accidents for the city region in the " << cityRegion << " region: ";
	cin >> accidents;

	// this loop does input validation of user input accidents
	while (accidents < 0.00) {
		cout << "You cannot enter a number of accidents less than 0!"
		     << "Enter the number of accidents for the city region in the " << cityRegion << " region: ";
		cin  >> accidents;
	}
	return accidents;

}

void findLowest (double N, double S, double E, double W, double C) {
	double lowest = N;
	string cityRegion = "North";

	if (S < lowest) {
		lowest = S;
		cityRegion = "South";
	}
	if (E < lowest) {
		lowest = E;
		cityRegion = "East";
	}
	if (W < lowest) {
		lowest = W;
		cityRegion = "West";
	}
	if (C < lowest) {
		lowest = C;
		cityRegion = "Central";
	}
	cout << "\n\n" << "The city region with the lowest accidents is the " << cityRegion << " region.\n"
		 << cityRegion << " had " << lowest << " accidents.";

}
