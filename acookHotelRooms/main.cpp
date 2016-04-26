#include <iostream>

using namespace std;

int main ()
{
	// declaring variables
	int hotelFloors;
	int hotelRoomsOnFloor;
	float hotelRoomsTotal = 0;
	int hotelRoomsOnFloorOccupied;
	float hotelRoomsOccupiedTotal = 0;

	// program

    // user input asking for number of hotel floors
	cout << "How many floors does the hotel have?";
	cin >> hotelFloors;
	// input validation of hotelFloors, ends the program if there are less than 1 floors entered.
	if (hotelFloors < 1) { cout << "You did not enter a valid number of floors!" << endl; return 0; }

	for (int i = 0; i != hotelFloors; hotelFloors --) {

		// this loop runs for all hotel floors EXCEPT floor 13
		if (hotelFloors != 13) {
            // user input asking for number of rooms on the current floor within the loop
            cout << "How many rooms are on floor #" << hotelFloors << "? Enter a number greater than 9." << endl;
            cin >> hotelRoomsOnFloor;
            // input validation of hotelRoomsOnFloor, ends the program if the user inputs a number of rooms on a floor less than 10
                if (hotelRoomsOnFloor < 10) { cout << "You did not enter a valid number of rooms on the floor!" << endl; return 0; }
            // user input asking for the number of currently occupied rooms on the floor within the loop
            cout << "How many rooms on floor #" << hotelFloors << " are currently occupied?" << endl;
            cin >> hotelRoomsOnFloorOccupied;
            // input validation of hotelRoomsOccupied, ends the program if the user inputs a number of occupied rooms greater than the number of rooms on the floor within the loop
                if (hotelRoomsOnFloor < hotelRoomsOnFloorOccupied ) { cout << "You entered more occupied rooms then there are on the floor!" << endl; return 0; }
            // calculating tally of running total rooms and total rooms occupied
            hotelRoomsTotal += hotelRoomsOnFloor;
            hotelRoomsOccupiedTotal += hotelRoomsOnFloorOccupied;
		}
	}
    // output of details of number of rooms and occupancy
    cout << "The total number of rooms in the hotel is:            " << hotelRoomsTotal << endl;
    cout << "The total number of occupied rooms in the hotel is:   " << hotelRoomsOccupiedTotal << endl;
    cout << "The total number of unoccupied rooms in the hotel is: " << hotelRoomsTotal - hotelRoomsOccupiedTotal << endl;
    cout << "The percentage of occupied rooms in the hotel is:     " << (hotelRoomsOccupiedTotal / hotelRoomsTotal) * 100/1 << "%" << endl;

    return 0;
}
