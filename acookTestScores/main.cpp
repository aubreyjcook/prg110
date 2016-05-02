#include <iostream>

using namespace std;

const int CAPACITY = 100;
const int TESTSCOREMAX = 1000;
int main()
{
    //creating dynamic arrays
    int *testScores;
    string *studentNames;
    testScores = new int[CAPACITY];
    studentNames = new string[CAPACITY];

    //declaring variables
    int maxTestScore;
    int studentRosterNumber;
    int holdTestScore;

    //program
    cout << "How many students were in the class?\n";
    cin >> studentRosterNumber;
    while(studentRosterNumber < 1 || studentRosterNumber > 100)
    {
        cout << "You must enter a number between 1 and 100, try again.\n" << "How many students were in the class?\n";
        cin >> studentRosterNumber;
    }

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
        cin >> *studentNames++;

        cout << "Enter the student's score: \n";
        cin >> holdTestScore;
        while(holdTestScore < 1 || holdTestScore > maxTestScore) { cout << "Error: You entered a score less than 1 or greater than " << maxTestScore << "\nEnter the student's score: \n"; cin >> holdTestScore; }
        *testScores = holdTestScore;
        *testScores++;
    }

    //ending program
    delete [] testScores;
    delete [] studentNames;
    testScores = NULL;
    studentNames = NULL;
    return 0;
}
