#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    cout << "  0 1 2n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << "|";
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "  -----n";
        }
    }
}

bool isWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();
    currentPlayer = 'X';
    int row, col;

    while (true) {
        printBoard();
        cout << "????? " << currentPlayer << ", ??????? ?????? ? ??????? (0-2): ";
        cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "???????????? ?????. ?????????? ?????." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (isWinner(currentPlayer)) {
            printBoard();
            cout << "???????????, ????? " << currentPlayer << " ???????!" << endl;
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "???? ???????? ??????!" << endl;
            break;
        }

        switchPlayer();
    }

    return 0;
}
