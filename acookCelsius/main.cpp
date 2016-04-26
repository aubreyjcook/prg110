#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
float celsius(float);

int main() {
	cout << "Fahrenheit to Celsius Conversion Table \n\n"
		 << "   F  |  C   \n"
		 << "-------------"; // this cout prints the header for the table

	for (float i = 0; i <= 20; i++) {

        // this if/else if changes the amount of white space in the columns for 1 or 2 digits
		if (i < 10){ cout << "\n" << setprecision(1) << fixed << showpoint << left
		 << "  " << i << " |" << celsius(static_cast<float>(i));}
        else if (i >= 10){ cout << "\n" << setprecision(1) << fixed << showpoint << left
		 << " " << i << " |" << celsius(static_cast<float>(i));}
	}
}

float celsius(float fahrenheit) {
	return (fahrenheit - 32) * (5.0/9.0);
}
