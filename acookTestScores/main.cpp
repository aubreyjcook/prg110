#include <iostream>

using namespace std;

void sortArray(int array[], int size);

int main()
{
    //creating pointers for dynamic array
    int *testScores;
    string *studentNames;

    //declaring variables
    int maxTestScore;
    int studentRosterNumber;
    int holdTestScore;

    //asking for number of students in the class
    cout << "How many students were in the class?\n";
    cin >> studentRosterNumber;
    while(studentRosterNumber < 1 || studentRosterNumber > 100)
    {
        cout << "You must enter a number between 1 and 100, try again.\n" << "How many students were in the class?\n";
        cin >> studentRosterNumber;
    }

    //generating an array based on user input for the number of students
    testScores = new int[studentRosterNumber];
    studentNames = new string[studentRosterNumber];

    cout << "What is the maximum test score?\n";
    cin >> maxTestScore;
    while (maxTestScore < 1 || maxTestScore > 1000)
    {
        cout << "You must enter a number between 1 and 1000, try again.\n" << "What is the maximum test score?\n";
        cin >> maxTestScore;
    }

    for (int i = 0; i < studentRosterNumber; i++)
    {
        cout << "Enter the student's Name: \n";
        cin >> studentNames[i];

        cout << "Enter the student's score: \n";
        cin >> holdTestScore;
        while(holdTestScore < 1 || holdTestScore > maxTestScore) { cout << "Error: You entered a score less than 1 or greater than " << maxTestScore << "\nEnter the student's score: \n"; cin >> holdTestScore; }
        testScores[i] = holdTestScore;
    }

    //sorting algorithm
    sortArray(testScores, studentRosterNumber);

    //display
    for (int i = 0; i < studentRosterNumber; i++)
    {
        cout << *(testScores + i) << " " << *(studentNames + i) << " ";
    }

    //ending program
    delete [] testScores;
    delete [] studentNames;
    testScores = NULL;
    studentNames = NULL;
    return 0;
}

void sortArray(int numbersToSort[], int arraySize){ // the bubble sort does not sort these names correctly

    bool swap;
    int temp;

    do {
        swap = false;
        for (int i = 0; i < (arraySize - 1); i++) {
            if (numbersToSort[i] < numbersToSort[i + 1]){
                temp = numbersToSort[i];
                numbersToSort[i] = numbersToSort[i + 1];
                numbersToSort[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}
