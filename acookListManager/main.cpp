#include <iostream>

using namespace std;

void whatDidUserPick(int userChoice); //for selecting the right function based on user input from the menu and sending them to the right function
void addMembers(string firstNames[], string lastNames[], string phoneNumbers[], int ages[], string tempFirstNames[], string tempLastNames[], string tempPhoneNumbers[], int tempAges[]); //for dynamically expanding and allocating the names and data of a member
void displayFunction(string firstNames[], string lastNames[], string phoneNumbers[], int ages[]); //for displaying the current list of members, it calls to functions to sort and display separately
void sortList(); //sorting algorithm
void displayList(string firstNames[], string lastNames[], string phoneNumbers[], int ages[]); //step through array and display
void clearList(); //clears the array and starts from the beginning

int arraySize = 0; //global variable containing the number of array members

int main()
{
    //declaring pointers, each must stand for a parallel array of member data
    string* firstNames         = new string[10];
    string* lastNames          = new string[10];
    string* phoneNumbers       = new string[10];
    int*    ages               = new int[10];

    string* tempFirstNames     = new string[1];
    string* tempLastNames      = new string[1];
    string* tempPhoneNumbers   = new string[1];
    int* tempAges              = new int[1];

	//declaring variables
	int userChoice;

    //array initialization
    *(firstNames + arraySize)   = {"null"};
    *(lastNames + arraySize)    = {"null"};
    *(phoneNumbers + arraySize) = {"null"};
    *(ages + arraySize)         = {0};

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

        switch(userChoice)
        {
            case 1:
                addMembers(firstNames, lastNames, phoneNumbers, ages, tempFirstNames, tempLastNames, tempPhoneNumbers, tempAges);
                break;
            case 2:
                displayFunction(firstNames, lastNames, phoneNumbers, ages);
                break;
            case 3:
                clearList();
                break;
            case 4:
                break;
        }
	} while (userChoice != 4);

	//closing program
	delete [] firstNames;
	delete [] lastNames;
	delete [] phoneNumbers;
	delete [] ages;
	firstNames = NULL;
	lastNames = NULL;
	phoneNumbers = NULL;
	ages = NULL;
	return 0;
}

void addMembers(string firstNames[], string lastNames[], string phoneNumbers[], int ages[], string tempFirstNames[], string tempLastNames[], string tempPhoneNumbers[], int tempAges[])
{
    //a counter for each time the array is increased in size by one
    arraySize++;

    //variables needed to add data to the array
    string newMemberFirstName;
    string newMemberLastName;
    string newMemberPhoneNumber;
    int newMemberAge;

    //getting the variables
    cout << "Enter the Member's First name: \n";
    cin  >> newMemberFirstName;
    cout << "Enter the Member's Last name: \n";
    cin  >> newMemberLastName;
    cout << "Enter the Member's phone number as a single string of numbers, eg(8154551234): \n";
    cin  >> newMemberPhoneNumber;
    cout << "Enter the Member's Age: \n";
    cin  >> newMemberAge;

    if (arraySize > 1) //reallocating the arrays
    {

        tempFirstNames   = new string[arraySize];
        tempLastNames    = new string[arraySize];
        tempPhoneNumbers = new string[arraySize];
        tempAges         = new int[arraySize];

        for(int i = 0; i < arraySize - 1; i++)
        {
            *(tempFirstNames + i) = firstNames[i];
            *(tempLastNames + i) = lastNames[i];
            *(tempPhoneNumbers + i) = phoneNumbers[i];
            *(tempAges + i) = ages[i];
        }

        delete          [] firstNames;
        delete          [] lastNames;
        delete          [] phoneNumbers;
        delete          [] ages;

        // This section of code is useless because it does not extend beyond the scope of this function, this makes it impossible to create a function that assigns a new array in this manner.
        firstNames       = new string[arraySize + 1];
        lastNames        = new string[arraySize + 1];
        phoneNumbers     = new string[arraySize + 1];
        ages             = new int[arraySize + 1];

        firstNames       = tempFirstNames;
        lastNames        = tempLastNames;
        phoneNumbers     = tempPhoneNumbers;
        ages             = tempAges;

    }

    //adding the data to the new array
    *(firstNames + (arraySize - 1))   = newMemberFirstName;
    *(lastNames + (arraySize - 1))    = newMemberLastName;
    *(phoneNumbers + (arraySize - 1)) = newMemberPhoneNumber;
    *(ages + (arraySize - 1))         = newMemberAge;

    cout << "New Member Added.\n";
}

void displayFunction(string firstNames[], string lastNames[], string phoneNumbers[], int ages[])
{
    sortList();
    displayList(firstNames, lastNames, phoneNumbers, ages);
}

void sortList()
{

}

void displayList(string firstNames[], string lastNames[], string phoneNumbers[], int ages[])
{
    if(arraySize >= 1){
        for(int i = 0; i < arraySize; i++)
        {
            cout << "first name: " << firstNames[i] << "\nlast name: " << lastNames[i] << "\nphone number: " << phoneNumbers[i] << "\nage: " << ages[i] << endl;
        }
    } else {cout << "Nothing to display." << endl;}
}

void clearList()
{

}
