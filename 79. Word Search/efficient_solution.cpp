#include <bits/stdc++.h>

using namespace std;

bool existHelper(vector<vector<char>>& board, string& word, int row, int col,
                 int wordIdx) {
    if (wordIdx == word.size() - 1) {
        return true;
    }

    board[row][col] -= 26;
    cout << "current Pos:" << row << ',' << col << '\n';

    int totalRows = board.size();
    int totalCols = board[0].size();

    bool res = false;
    pair<int, int> newPos;

    // left
    if (col > 0 && board[row][col - 1] == word[wordIdx + 1] &&
        existHelper(board, word, row, col - 1, wordIdx + 1)) {
        return true;
    }

    // right
    if (col < totalCols - 1 && board[row][col + 1] == word[wordIdx + 1] &&
        existHelper(board, word, row, col + 1, wordIdx + 1)) {
        return true;
    }

    // top
    if (row > 0 && board[row - 1][col] == word[wordIdx + 1] &&
        existHelper(board, word, row - 1, col, wordIdx + 1)) {
        return true;
    }

    // bottom
    if (row < totalRows - 1 && board[row + 1][col] == word[wordIdx + 1] &&
        existHelper(board, word, row + 1, col, wordIdx + 1)) {
        return true;
    }

    board[row][col] += 26;
    cout << "Returning\n";
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == word[0]) {
                cout << "============\n";
                bool res = existHelper(board, word, row, col, 0);
                if (res) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    vector<vector<char>> board2 = {{'a'}};
    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    string word1 = "ABCB";
    string word2 = "a";
    string word3 = "ABCCED";

    cout << exist(board1, word1) << '\n';
    cout << exist(board2, word2) << '\n';
    cout << exist(board3, word3) << '\n';

    return 0;
}