#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float getJudgeData(unsigned int numberOfDecimalsToKeep); // this is a function prototype for writing the array data
void calcScore(float [], int); // this is a function prototype for calculating the average score from the array

float findLowest(float [], int); // this is a function prototype for finding the lowest score
float findHighest(float [], int); // this is a function prototype for finding the highest score

int main()
{
    const int JUDG_NUM = 20; // this constant is the maximum number of judges
    float judgeScores[JUDG_NUM]; // this is the array that holds the judge scores
    int judges; // this is a variable that reads the number of judges entered by the user

    cout << "Enter the number of judges.\n";
    cin >> judges; // user input for number of judges
    while (judges < 5 || judges > 20) { // this while loop is input validation for the number of judges
        cout << "The number of judges must be between 5 and 20.\n"
             << "Enter the number of judges.\n";
        cin >> judges;
    }

    for (int i = 0; i < judges; i++) {
        judgeScores[i] = getJudgeData(1); // the number of decimals to hold the score are passed to the getJudgeData Function
    }
    calcScore(judgeScores, judges);

    return 0;
}

float getJudgeData(unsigned int numberOfDecimalsToKeep) {
    float judgeScore;
    cout << "Enter the judge's score as a floating point number (eg. 9.3): \n";
    cin >> judgeScore;

    while (judgeScore < 0 || judgeScore > 10 ) { // this while loop validates the score
        cout << "The score must be a number greater than 0 and less than 10. Please re enter.\n"
             << "Enter the judge's score as a floating point number (eg. 9.3): \n";
        cin  >> judgeScore;
    }
	judgeScore = roundf(judgeScore * powf(10, numberOfDecimalsToKeep)) / powf(10, numberOfDecimalsToKeep); // this truncates the score to one decimal place
	return judgeScore;
}

void calcScore(float judgeScores[], int judges) {
    float score = 0;
    for (int i = 0; i < judges; i++){
        score += judgeScores[i];
    }
    score = score - (findLowest(judgeScores, judges) + findHighest(judgeScores, judges));
    score = score / (judges - 2);

    cout << "The final score is: " << fixed << showpoint << setprecision(1) << score;
}

float findLowest(float judgeScores[], int judges) {
    float lowest = judgeScores[0];
    for (int i = 1; i < judges; i++){
        if (judgeScores[i] < lowest){ lowest = judgeScores[i];}
    }
    return lowest;
}

float findHighest(float judgeScores[], int judges) {
    float highest = judgeScores[0];
    for (int i = 1; i < judges; i++){
        if (judgeScores[i] > highest){ highest = judgeScores[i];}
    }
    return highest;
}
