#include <iostream>

using namespace std;

void sortArray(float arrayScores[], string arrayNames[], int size);
float calculateAverageScore(int);

int main()
{
    //creating pointers for dynamic array
    float *testScores;
    string *studentNames;

    //declaring variables
    float maxTestScore;
    int studentRosterNumber;
    float holdTestScore;

    //asking for number of students in the class
    cout << "How many students were in the class?\n";
    cin >> studentRosterNumber;
    while(studentRosterNumber < 1 || studentRosterNumber > 100)
    {
        cout << "You must enter a number between 1 and 100, try again.\n" << "How many students were in the class?\n";
        cin >> studentRosterNumber;
    }

    //generating an array based on user input for the number of students
    testScores = new float[studentRosterNumber];
    studentNames = new string[studentRosterNumber];

    //getting more information about the test scores
    cout << "What is the maximum test score?\n";
    cin >> maxTestScore;
    while (maxTestScore < 1 || maxTestScore > 1000)
    {
        cout << "You must enter a number between 1 and 1000, try again.\n" << "What is the maximum test score?\n";
        cin >> maxTestScore;
    }

    //filling the array with student names and scores
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
    sortArray(testScores, studentNames, studentRosterNumber);

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

void sortArray(float numbersToSort[], string namesToSort[], int arraySize)
{ //bubble sort for descending order of parallel arrays

    bool swap;
    float temp;
    string temp2;

    do {
        swap = false;
        for (int i = 0; i < (arraySize - 1); i++) {
            if (numbersToSort[i] < numbersToSort[i + 1]){
                temp = numbersToSort[i]; temp2 = namesToSort[i];
                numbersToSort[i] = numbersToSort[i + 1]; namesToSort[i] = namesToSort[i + 1];
                numbersToSort[i + 1] = temp; namesToSort[i + 1] = temp2;
                swap = true;
            }
        }
    } while (swap);
}

float calculateAverageScore(float scoreArray[])
{
    float total = 0;

    for(int i = 0; i < arrayMax; i++)
    {
        total += scoreArray[i];
    }

    return total;
}
