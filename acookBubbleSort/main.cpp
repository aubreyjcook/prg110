#include <iostream>
#include <string>

using namespace std;

const int NUM_NAMES = 20;

void displayNames(string namesToDisplay[NUM_NAMES]);
void sortNames(string[], int);

int main()
{
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };

    cout << "unsorted names: \n";
    displayNames(names);
    sortNames(names, NUM_NAMES);
    cout << endl << "\nsorted names: \n";
    displayNames(names);
	return 0;
}

void displayNames(string namesToDisplay[]) { // display every four names before making a new line
    for(int i = 0; i < 20; i++) {
        cout << namesToDisplay[i] << ". ";
        if (((i + 1) % 4) == 0) {
            cout << "\n";
        }
    }

}

void sortNames(string namesToSort[], int arraySize){ // the bubble sort does not sort these names correctly

    bool swap;
    string temp;

    do {
        swap = false;
        for (int i = 0; i < (arraySize - 1); i++) {
            if (namesToSort[i] > namesToSort[i + 1]){
                temp = namesToSort[i];
                namesToSort[i] = namesToSort[i + 1];
                namesToSort[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}
