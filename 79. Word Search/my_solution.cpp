#include <bits/stdc++.h>

using namespace std;
map<string, pair<int, int>> neighbors = {{"left", make_pair(0, -1)},
                                         {"right", make_pair(0, +1)},
                                         {"top", make_pair(-1, 0)},
                                         {"bottom", make_pair(+1, 0)}};

bool existHelper(vector<vector<char>>& board, string word,
                 pair<int, int> curPos, set<pair<int, int>>& visited,
                 int wordIdx) {
    if (wordIdx == word.size()) {
        return true;
    } else {
        cout << "current Pos" << curPos.first << ' ' << curPos.second << '\n';
        // visited.insert(curPos);

        // neighbors

        int totalRows = board.size();
        int totalCols = board[0].size();
        pair<int, int> newPos;
        for (auto e : neighbors) {
            
            newPos = make_pair(curPos.first+e.second.first, curPos.second+e.second.second);

            if(newPos.first<0 || newPos.first>=totalRows || newPos.second<0 || newPos.second>=totalCols){
                continue;
            }

            if(visited.find(newPos)!=visited.end()){
                continue;
            }

            // if(board[newPos.first][newPos.second]==word[wordIdx]){
                cout<<"Going "<<e.first<<".....\n";
                bool res = existHelper(board, word, newPos, visited, wordIdx + 1);
                if(res){
                    return true;
                }
            //}
        }
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word) {
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == word[0]) {
                cout << "============\n";
                set<pair<int, int>> s;
                bool res = existHelper(board, word, make_pair(row, col), s, 1);
                if (res) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";

    cout << exist(board, word);
    return 0;
}