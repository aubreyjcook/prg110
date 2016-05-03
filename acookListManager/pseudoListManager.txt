#include <iostream>

using namespace std;

void whatDidUserPick(int userChoice);
void addMembers();
void displayList();
void doSomething();

int main()
{
	//declaring variables
	int userChoice;

	do //this do-while statement controls for the exit functionality of the program
	{
		//displaying menu and getting user selection
		cout << "Choose an option: \n"
			 << "1. Add Members.\n"
			 << "2. Display List.\n"
			 << "3. Exit.\n"
			 << "4. Do something.\n";
		cin  >> userChoice;

		//input validation for the menu
		while (userChoice < 1 || userChoice > 4)
		{
			cout << "Wrong Answer.\n"
				 << "Choose an option: \n"
				 << "1. Add Members.\n"
				 << "2. Display List.\n"
				 << "3. Exit.\n"
				 << "4. Do something.\n";
			cin  >> userChoice;
		}

		whatDidUserPick(userChoice);
	} while (userChoice != 3);
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
            displayList();
            break;
        case 3:
            break;
        case 4:
            doSomething();
            break;
	}
}

void addMembers()
{

}

void displayList()
{

}
void doSomething()
{

}
