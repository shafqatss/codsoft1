#include <iostream>
#include <vector>

const int SIZE = 3;

// Function to display the board
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < SIZE - 1) std::cout << "---------" << "\n";
    }
    std::cout << "\n";
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
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

// Function to check for a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool playAgain = true;

    while (playAgain) {
        // Initialize the board
        std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;

        while (!gameWon && !checkDraw(board)) {
            displayBoard(board);
            int row, col;
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            // Validate input
            if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != ' ') {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            // Update the board
            board[row - 1][col - 1] = currentPlayer;

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        if (!gameWon) {
            displayBoard(board);
            std::cout << "The game is a draw.\n";
        }

        // Ask if players want to play again
        char response;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> response;
        playAgain = (response == 'y' || response == 'Y');
    }

    std::cout << "Thank you for playing!\n";
    return 0;
}