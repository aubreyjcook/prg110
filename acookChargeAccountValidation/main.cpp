#include <iostream>

using namespace std;

const int ACCOUNT_NUM = 18;

//void displayAccount(int accountToDisplay[ACCOUNT_NUM]); /* *** This is a dummy display function to check for array init *** */

int searchList(const int [], int, int);

int main()
{
    int accountArray[ACCOUNT_NUM] = {
     5658845,     4520125,     7895122,     8777541,     8451277,     1302850,

     8080152,     4562555,     5552012,     5050552,     7825877,     1250255,

     1005231,     6545231,     7576651,     7576652,     7881200,     4581002
    };

    int accountInput;
    int results;
    bool checkAgain;
    char checkInput;

    do {

    cout << "Enter a charge account number to see if it is in the list.\n";
    cin >> accountInput;
    while (accountInput < 0) {
    cout << "The numbers entered were not valid, try again.\n";
    cin >> accountInput;}

    results = searchList(accountArray, ACCOUNT_NUM, accountInput);

    if (results == -1) {cout << "Number not found.\n";} else { cout << "Yes, that number exists.\n";}

    cout << "Check another number? Y/N\n";
    cin >> checkInput;

    if (checkInput == 'Y' || checkInput == 'y') {checkAgain = true;} else {checkAgain = false;}

    } while (checkAgain);
    //displayAccount(accountArray); /* *** This is a dummy display function to check for array init *** */
    return 0;
}

int searchList(const int list[], int numElems, int value){
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < numElems && !found){
        if (list[index] == value) {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

/*void displayAccount(int accountToDisplay[]) { // display every four names before making a new line
    for(int i = 0; i < 18; i++) {
        cout << accountToDisplay[i] << ". ";
        if (((i + 1) % 4) == 0) {
            cout << "\n";
        }
    }

}*/ /* *** This is a dummy display function to check for array init *** */
