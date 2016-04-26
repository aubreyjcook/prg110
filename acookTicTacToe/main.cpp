#include <iostream>
#include <cstdlib>

using namespace std;

char gameBoard[3][3]{{'u','u','u'},
                     {'u','u','u'},
                     {'u','u','u'}};


void getWinner();
void getPlayerChoices();
void displayBoard();

bool winner = false;

int main()
{
    int tieCount = 0;
    cout << "Let's play tic-tac-toe!\n";
    displayBoard();
    while(winner == false && tieCount < 4) {getPlayerChoices(); tieCount++;}
    cout << "The game is tied. The end.";
    return 0;
}

void getPlayerChoices() {
    int playerColumn;
    int playerRow;

    for (int i = 1; i < 3; i++){
        if (winner == true) {exit(0);}
        cout << "Player " << i <<" select a spot to mark on the board.\nEnter the column:\n";
        cin >> playerColumn;
        while (playerColumn < 1 || playerColumn > 3) {
            cout << "You must enter a integer between 1 and 3. Try again:\n";
            cin >> playerColumn;
        }
        cout << "Enter the row:\n";
        cin >> playerRow;
        while (playerRow < 1 || playerRow > 3) {
            cout << "You must enter a integer between 1 and 3. Try again:\n";
            cin >> playerRow;
        }
        if (winner == true) {exit(0);}
        while (gameBoard[playerRow - 1][playerColumn - 1] == 'X' || gameBoard[playerRow - 1][playerColumn - 1] == 'O') { // this while loop checks if the input attempts to overwrite a previous player's choice and forces a new one if it is
            if (winner == true) {exit(0);}
                cout << "You cannot overwrite a player's previous spot on the board. Try again.\nEnter the column:\n";
                cin >> playerColumn;
            while (playerColumn < 1 || playerColumn > 3) {
                cout << "You must enter a integer between 1 and 3. Try again:\n";
                cin >> playerColumn;
            }
            cout << "Enter the row:\n";
            cin >> playerRow;
            while (playerRow < 1 || playerRow > 3) {
                cout << "You must enter a integer between 1 and 3. Try again:\n";
                cin >> playerRow;
        } }
        if (i == 1) {gameBoard[playerRow - 1][playerColumn - 1] = 'X';} else {gameBoard[playerRow - 1][playerColumn - 1] = 'O';}
        displayBoard();
        getWinner();
        }
}

void displayBoard() {
    cout << "  | 1 ~ 2 ~ 3 |" << endl;

    for (int i = 0; i < 3; i++){ for (int j = 0; j < 3; j++) {
        if (j == 0) {cout << i + 1 << " ";}
        cout << "| " << gameBoard[i][j] << " ";
        if (j == 2) {cout << "|" << endl;}
    } }
}

void getWinner() {

    for (int i = 0; i < 3; i++){ // this for loop checks for a winner in a horizontal row
        if (gameBoard[i][0] != 'u' && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            cout << "We have a winner!\n"; winner = true;
            if(gameBoard[i][0] == 'X') {cout << "The winner is player 1!";} else {cout << "The winner is player 2!";}}}

    for (int i = 0; i < 3; i++){ // this for loop checks for a winner in a vertical column
        if (gameBoard[0][i] != 'u' && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
            cout << "We have a winner!\n"; winner = true;
            if(gameBoard[0][i] == 'X') {cout << "The winner is player 1!";} else {cout << "The winner is player 2!";}}}

    if (gameBoard[0][0] != 'u' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) { // this if statement checks for a winner in a cross
        cout << "We have a winner!\n"; winner = true;
        if(gameBoard[0][0] == 'X') {cout << "The winner is player 1!";} else {cout << "The winner is player 2!";}}

    if (gameBoard[2][0] != 'u' && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2]) { // this if statement checks for a winner in a cross
        cout << "We have a winner!\n"; winner = true;
        if(gameBoard[2][0] == 'X') {cout << "The winner is player 1!";} else {cout << "The winner is player 2!";}}
}
