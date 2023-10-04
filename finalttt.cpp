#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const char board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const char board[3][3], char symbol) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true; // Row win
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true; // Column win
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

int main() {
    string p1, p2;
    int row, col;
    char box[3][3]; // Change to char array (not const)

    // Initialize the Tic-Tac-Toe board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            box[i][j] = '-';
        }
    }

    // Get player names
    cout << "Who's player 1? ";
    cin >> p1;
    cout << "Who's player 2? ";
    cin >> p2;

    // Choose player symbols
    char symbol1, symbol2;
    cout << p1 << ", choose your symbol (x or o): ";
    cin >> symbol1;
    if (symbol1 == 'x') {
        symbol2 = 'o';
        cout << p1 << " will play as x, and " << p2 << " will play as o." << endl;
    } else if (symbol1 == 'o') {
        symbol2 = 'x';
        cout << p1 << " will play as o, and " << p2 << " will play as x." << endl;
    } else {
        cout << "Invalid symbol. Exiting the game." << endl;
        return 1;
    }

    char currentPlayer = symbol1;
    int moves = 0;
    bool gameOver = false;

    while (!gameOver && moves < 9) {
        displayBoard(box);

        // Get player's move
        cout << "Player " << (currentPlayer == symbol1 ? p1 : p2) << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check for valid move
        if (row < 0 || row > 2 || col < 0 || col > 2 || box[row][col] != '-') {
            cout << "Invalid move. Try again." << endl;
            continue; // Repeat the loop for a valid move
        }

        // Make the move
        box[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(box, currentPlayer)) {
            displayBoard(box);
            cout << "Player " << (currentPlayer == symbol1 ? p1 : p2) << " wins!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == symbol1) ? symbol2 : symbol1;
            moves++;
        }
    }

    // If no one wins after 9 moves, it's a draw
    if (!gameOver) {
        displayBoard(box);
        cout << "It's a draw!" << endl;
    }

    return 0;
}
