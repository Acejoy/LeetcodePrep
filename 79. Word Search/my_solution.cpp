#include <bits/stdc++.h>

using namespace std;
map<string, pair<int, int>> neighbors = {{"left", make_pair(0, -1)},
                                         {"right", make_pair(0, +1)},
                                         {"top", make_pair(-1, 0)},
                                         {"bottom", make_pair(+1, 0)}};

bool existHelper(vector<vector<char>>& board, string word,
                 pair<int, int> curPos, int wordIdx,
                 set<pair<int, int>> visited) {
    if (wordIdx == word.size()) {
        return true;
    } else {
        int totalRows = board.size();
        int totalCols = board[0].size();
        pair<int, int> newPos;

        cout << "current Pos" << curPos.first << ' ' << curPos.second << '\n';

        if (curPos.first < 0 || curPos.first >= totalRows ||
            curPos.second < 0 || curPos.second >= totalCols) {
            return false;
        }

        if (board[curPos.first][curPos.second] != word[wordIdx]) {
            cout << "Returning\n";
            return false;
        }

        visited.insert(curPos);

        for (auto e : neighbors) {
            newPos = make_pair(curPos.first + e.second.first,
                               curPos.second + e.second.second);

            if (visited.find(newPos) != visited.end()) {
                continue;
            }

            cout << "Going " << e.first << ".....\n";
            bool res = existHelper(board, word, newPos, wordIdx + 1, visited);
            if (res) {
                return true;
            }
        }
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word) {
    set<pair<int, int>> s;
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == word[0]) {
                cout << "============\n";
                bool res = existHelper(board, word, make_pair(row, col), 0, s);
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
    string word1 = "ABCB";
    string word2 = "a";

    cout << exist(board2, word2);
    return 0;
}