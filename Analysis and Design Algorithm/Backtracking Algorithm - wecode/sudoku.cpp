#include <iostream>
#include <vector>
using namespace std;

bool Check(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool Sudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 'X') {
                for (char c = '1'; c <= '9'; c++) {
                    if (Check(board, i, j, c)) {
                        board[i][j] = c;
                        if (Sudoku(board)) return true;
                        board[i][j] = 'X';
                    }
                }
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
            if (j < 8) cout << " ";
        }
        cout << endl;
    }
    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    Sudoku(board);

    return 0;
}