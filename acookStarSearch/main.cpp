#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void getJudgeData(float &, unsigned int numberOfDecimalsToKeep);
void calcScore(float, float, float, float, float);

float findLowest(float, float, float, float, float);
float findHighest(float, float, float, float, float);

int main()
{
	float judgeScore1;
    float judgeScore2;
    float judgeScore3;
    float judgeScore4;
    float judgeScore5;

    getJudgeData(judgeScore1, 1);
    getJudgeData(judgeScore2, 1);
    getJudgeData(judgeScore3, 1);
    getJudgeData(judgeScore4, 1);
    getJudgeData(judgeScore5, 1);

    calcScore(judgeScore1, judgeScore2, judgeScore3, judgeScore4, judgeScore5);

    return 0;
}

void getJudgeData(float &judgeScore, unsigned int numberOfDecimalsToKeep) {
	cout << "Enter the judge's score as a floating point number (eg. 9.3): \n";
	cin >> judgeScore;

	while (judgeScore < 0 || judgeScore > 10 ) {
		cout << "The score must be a number greater than 0 and less than 10. Please re enter.\n"
			 << "Enter the judge's score as a floating point number (eg. 9.3): \n";
		cin >> judgeScore;
	}

	judgeScore = roundf(judgeScore * powf(10, numberOfDecimalsToKeep)) / powf(10, numberOfDecimalsToKeep); // this truncates the score to one decimal place
}

void calcScore(float judgeScore1, float judgeScore2, float judgeScore3, float judgeScore4, float judgeScore5) {
    float score = judgeScore1 + judgeScore2 + judgeScore3 + judgeScore4 + judgeScore5 - (findLowest(judgeScore1, judgeScore2, judgeScore3, judgeScore4, judgeScore5) + findHighest(judgeScore1, judgeScore2, judgeScore3, judgeScore4, judgeScore5));
    score = score / 3.0;

    cout << "The final score is: " << fixed << showpoint << setprecision(1) << score;
}

float findLowest(float judgeScore1, float judgeScore2, float judgeScore3, float judgeScore4, float judgeScore5) {
        float lowest = judgeScore1;

        if (judgeScore2 < lowest) {
            lowest = judgeScore2;
        }
        if (judgeScore3 < lowest) {
            lowest = judgeScore3;
        }
        if (judgeScore4 < lowest) {
            lowest = judgeScore4;
        }
        if (judgeScore5 < lowest) {
            lowest = judgeScore5;
        }

	return lowest;
}

float findHighest(float judgeScore1, float judgeScore2, float judgeScore3, float judgeScore4, float judgeScore5) {
        float highest = judgeScore1;

        if (judgeScore2 > highest) {
            highest = judgeScore2;
        }
        if (judgeScore3 > highest) {
            highest = judgeScore3;
        }
        if (judgeScore4 > highest) {
            highest = judgeScore4;
        }
        if (judgeScore5 > highest) {
            highest = judgeScore5;
        }

	return highest;
}
