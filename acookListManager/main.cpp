#include <iostream>

using namespace std;

void addMembers      (string firstNames[], string lastNames[], string phoneNumbers[], int ages[], string tempFirstNames[], string tempLastNames[], string tempPhoneNumbers[], int tempAges[]);
//for dynamically expanding and allocating the names and data of a member
void displayFunction (string firstNames[], string lastNames[], string phoneNumbers[], int ages[]);
//for displaying the current list of members, it calls to functions to sort and display separately
void sortList        (string firstNames[], string lastNames[], string phoneNumbers[], int ages[]);
//sorting algorithm
void displayList     (string firstNames[], string lastNames[], string phoneNumbers[], int ages[]);
//step through array and display
void clearList       (string firstNames[], string lastNames[], string phoneNumbers[], int ages[]);
//clears the array and starts from the beginning

int arraySize = 0;
//global variable containing the number of array elements that have been assigned, it increments every time the add member function is run and resets when the clear option is selected
const int ARRAYMAX = 10;

int main()
{
    //declaring pointers, each must stand for a parallel array of member data
    string* firstNames         = new string[ARRAYMAX];
    string* lastNames          = new string[ARRAYMAX];
    string* phoneNumbers       = new string[ARRAYMAX];
    int*    ages               = new int[ARRAYMAX];

    string* tempFirstNames     = new string[0];
    string* tempLastNames      = new string[0];
    string* tempPhoneNumbers   = new string[0];
    int* tempAges              = new int[0];

	//declaring variables
	int userChoice;

    //array initialization
    for(int i = 0; i < ARRAYMAX; i++)
    {
        *(firstNames + i)   = "zzzz";
        *(lastNames + i)    = "zzzz";
        *(phoneNumbers + i) = "zzzz";
        *(ages + i)         = 5555;
    }

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
                clearList(firstNames, lastNames, phoneNumbers, ages);
                break;
            case 4:
                break;
        }
	} while (userChoice != 4);

	//closing program
	delete [] firstNames;   delete [] tempFirstNames;
	delete [] lastNames;    delete [] tempLastNames;
	delete [] phoneNumbers; delete [] tempPhoneNumbers;
	delete [] ages;         delete [] tempAges;
	firstNames   = NULL; tempFirstNames   = NULL;
	lastNames    = NULL; tempLastNames    = NULL;
	phoneNumbers = NULL; tempPhoneNumbers = NULL;
	ages         = NULL; tempAges         = NULL;
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

    if (arraySize > 1) //copy array operation from original array to temporary array then back to the original
    {
        //clearing the temp array and rebuilding so it can store the temporary elements
        tempFirstNames   = NULL; tempFirstNames   = new string[arraySize];
        tempLastNames    = NULL; tempLastNames    = new string[arraySize];
        tempPhoneNumbers = NULL; tempPhoneNumbers = new string[arraySize];
        tempAges         = NULL; tempAges         = new int[arraySize];

        for(int i = 0; i < arraySize - 1; i++)
        {
            //copying into temporary array
            *(tempFirstNames + i)   = firstNames[i];
            *(tempLastNames + i)    = lastNames[i];
            *(tempPhoneNumbers + i) = phoneNumbers[i];
            *(tempAges + i)         = ages[i];
        }

        /* this section of code would normally be how the original array is cleared and expanded, but it does not extend beyond the scope of this function
        firstNames   = NULL; firstNames   = new string[arraySize];
        lastNames    = NULL; lastNames    = new string[arraySize];
        phoneNumbers = NULL; phoneNumbers = new string[arraySize];
        ages         = NULL; ages         = new int[arraySize];
        */

        for(int i = 0; i < arraySize - 1; i++)
        {
            //copying into the true array
            *(firstNames + i)       = tempFirstNames[i];
            *(lastNames + i)        = tempLastNames[i];
            *(phoneNumbers + i)     = tempPhoneNumbers[i];
            *(ages + i)             = tempAges[i];
        }

        delete [] tempFirstNames;
        delete [] tempLastNames;
        delete [] tempPhoneNumbers;
        delete [] tempAges;
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
    sortList(firstNames, lastNames, phoneNumbers, ages);
    displayList(firstNames, lastNames, phoneNumbers, ages);
}

void sortList(string firstNames[], string lastNames[], string phoneNumbers[], int ages[])
{
    bool swap;
    string swapFirstNames;
    string swapLastNames;
    string swapPhoneNumbers;
    int swapAges;

    do { //sort the last names, parallel sorting
        swap = false;
        for (int i = 0; i < (arraySize - 1); i++) {
            if (lastNames[i] > lastNames[i + 1]){
                swapLastNames = lastNames[i]; swapFirstNames = firstNames[i]; swapPhoneNumbers = phoneNumbers[i]; swapAges = ages[i];
                lastNames[i] = lastNames[i + 1]; firstNames[i] = firstNames[i + 1]; phoneNumbers[i] = phoneNumbers[i + 1]; ages[i] = ages[i + 1];
                lastNames[i + 1] = swapLastNames; firstNames[i + 1] = swapFirstNames; phoneNumbers[i + 1] = swapPhoneNumbers; ages[i + 1] = swapAges;
                swap = true;
            }
        }
    } while (swap);


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

void clearList(string firstNames[], string lastNames[], string phoneNumbers[], int ages[])
{
    char startOver;

    cout << "Delete all entries and start over? y/n\n";
    cin >> startOver;

    while(startOver != 'y' && startOver != 'n' && startOver != 'Y' && startOver != 'N')
    {
        cout << "Delete all entries and start over? y/n\n";
        cin >> startOver;
    }

    if (startOver == 'y' || startOver == 'Y')
    {
        cout << "Okay. Erasing array.\n";

        for(int i = 0; i < ARRAYMAX; i++)
        {
            *(firstNames + i)   = "zzzz";
            *(lastNames + i)    = "zzzz";
            *(phoneNumbers + i) = "zzzz";
            *(ages + i)         = 5555;
        }

        arraySize = 0;

        cout << "Array erased." << endl;
    }
}
