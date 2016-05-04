#include <iostream>

using namespace std;

void whatDidUserPick(int userChoice); //for selecting the right function based on user input from the menu and sending them to the right function
void addMembers(); //for dynamically expanding and allocating the names and data of a member
void displayFunction(); //for displaying the current list of members, it calls to functions to sort and display separately
void sortList(); //sorting algorithm
void displayList(); //step through array and display
void clearList(); //clears the array and starts from the beginning

int main()
{
    //declaring pointers, each must stand for a parallel array of member data
    *string firstNames;
    *string lastNames;
    *unsigned long int phoneNumber;
    *int age;

	//declaring variables
	int userChoice;

	do //this do-while statement controls for the exit functionality of the program
	{
		//displaying menu and getting user selection
		cout << "Choose an option: \n"
			 << "1. Add Members.\n"
			 << "2. Display List.\n"
			 << "3. Clear.\n"
			 << "4. Exit.\n";
		cin  >> userChoice;

		//input validation for the menu
		while (userChoice < 1 || userChoice > 4)
		{
			cout << "Wrong Answer.\n"
				 << "Choose an option: \n"
				 << "1. Add Members.\n"
				 << "2. Display List.\n"
				 << "3. Clear.\n"
				 << "4. Exit.\n";
			cin  >> userChoice;
		}

		whatDidUserPick(userChoice);
	} while (userChoice != 4);

	//closing program
	return 0;
}

void whatDidUserPick(int userChoice)
{
	switch(userChoice)
	{
        case 1:
            addMembers();
            break;
        case 2:
            displayFunction();
            break;
        case 3:
            clearList();
            break;
        case 4:
            break;
	}
}

void addMembers()
{

}

void displayFunction()
{
    sortList();
    displayList();
}

void sortList()
{

}

void displayList()
{

}

void clearList()
{

}
