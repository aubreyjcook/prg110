#include <iostream>

using namespace std;

//global constants

const int MONK_NUM = 3;
const int TBL_COLM = 7;

int findLowest(int foodTable[][TBL_COLM]);
int findHighest(int foodTable[][TBL_COLM]);

int main()
{
    int input;

    int foodTable[MONK_NUM][TBL_COLM];

    for (int j = 0; j < 3; j++) {
        for(int i = 0; i < 7; i++) {
            cout << "Enter the number of pounds eaten by monkey number " << j + 1 << " on day " << i + 1 << "\n";
            cin >> input;
            while (input < 0) {
                cout << "Input for the number of pounds cannot be negative.\n"
                     << "Enter the number of pounds eaten by monkey number " << j + 1 << " on day " << i + 1 << "\n";
                cin >> input;
            }

            foodTable[j][i] = input;
        }
    }

    int avgEaten = 0;

    for (int j = 0; j < 3; j ++) {
        for(int i = 0; i < 7; i++) {
            avgEaten = avgEaten + foodTable[j][i];
        }
    }

    cout << "The average food eaten per day by the tiny monkeys is: " << avgEaten / 3 << endl;
    cout << "The least amount of food eaten by one tiny hungry monkey is: " << findLowest(foodTable) << endl;
    cout << "The greatest amount of food eaten by one tiny fat monkey is: " << findHighest(foodTable) << endl;
    return 0;
}

int findLowest(int foodTable[][TBL_COLM]) {
    int lowest = foodTable[0][0];
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 7; i++){
            if (foodTable[j][i] < lowest){ lowest = foodTable[j][i];}
    }
    }
    return lowest;
}

int findHighest(int foodTable[][TBL_COLM]) {
    int highest = foodTable[0][0];
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 7; i++){
            if (foodTable[j][i] > highest){ highest = foodTable[j][i];}
    }
    }
    return highest;
}
