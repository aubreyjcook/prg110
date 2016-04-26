#include <iostream>
#include <string>

using namespace std;

void selectionSort(int [], int);
void selectionSortString(string [], int);

int binarySearch(const int[], int, int);

//void displayAccount(int accountToDisplay[]); /* *** This is a dummy display function to check for array init *** */
//void displayNames(string namesToDisplay[]);

int main()
{
    const int MAX_ACCTS = 18;

    int account[MAX_ACCTS] = {
        5658845,4520125,7895122,8777541,8451277,1302850,
        8080152,4562555,5552012,5050552,7825877,1250255,
        1005231,6545231,7576651,7576652,7881200,4581002};

    string name[] = {
        "Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy"};

    selectionSort(account, MAX_ACCTS);
    selectionSortString(name, MAX_ACCTS);

    int returnPosition;
    int accountInput;
    bool checkAgain;
    char checkInput;

    do
    {

    cout << "Enter a charge account number to see if it is in the list.\n";
    cin >> accountInput;
    while (accountInput < 0) // input validation
    {
    cout << "The numbers entered were not valid, try again.\n";
    cin >> accountInput;
    }

    returnPosition = binarySearch(account, MAX_ACCTS, accountInput);

    if (returnPosition == -1) {cout << "Number not found.\n";} else { cout << "Yes, that account number exists.\nThe name associated with the account is: " << name[returnPosition] << endl;}

    cout << "Check another number? Y/N\n";
    cin >> checkInput;

    if (checkInput == 'Y' || checkInput == 'y') {checkAgain = true;} else {checkAgain = false;}

    } while (checkAgain);
    //displayAccount(account);
    //displayNames(name);

    return 0;
}

void selectionSort(int account[], int size)
{
    int startScan, minIndex, minValue;

    for(startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = account[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if(account[index] < minValue)
            {
                minValue = account[index];
                minIndex = index;
            }
        }
        account[minIndex] = account[startScan];
        account[startScan] = minValue;
    }
}

void selectionSortString(string account[], int size)
{
    int startScan, minIndex;

    for(startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        string minValue = account[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if(account[index] < minValue)
            {
                minValue = account[index];
                minIndex = index;
            }
        }
        account[minIndex] = account[startScan];
        account[startScan] = minValue;
    }
}

/*void displayAccount(int accountToDisplay[]) { // display every four names before making a new line
    for(int i = 0; i < 18; i++) {
        cout << accountToDisplay[i] << ". ";
        if (((i + 1) % 4) == 0) {
            cout << "\n";
        }
    }

} /* *** This is a dummy display function to check for array init *** */

/*void displayNames(string namesToDisplay[])
{ // display every four names before making a new line
    for(int i = 0; i < 20; i++) {
        cout << namesToDisplay[i] << ". ";
        if (((i + 1) % 4) == 0) {
            cout << "\n";
        }
    }
} /**/

int binarySearch(const int array[], int size, int value)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}
