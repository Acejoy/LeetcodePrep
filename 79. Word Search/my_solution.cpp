#include <bits/stdc++.h>

using namespace std;
map<string, pair<int, int>> neighbors = {{"left", make_pair(0, -1)},
                                         {"right", make_pair(0, +1)},
                                         {"top", make_pair(-1, 0)},
                                         {"bottom", make_pair(+1, 0)}};

bool existHelper(vector<vector<char>>& board, string& word,
                 pair<int, int> curPos, int wordIdx, vector<vector<bool>>& visited) {
    
    
    if(wordIdx==word.size()-1){
        return true;
    }
    visited[curPos.first][curPos.second] = true;
    cout<<"current Pos:"<<curPos.first<<','<<curPos.second<<'\n';
    
    int totalRows = board.size();
    int totalCols = board[0].size();
            
    bool res = false;
    pair<int,int> newPos;

    for (auto e : neighbors) {

        newPos = make_pair(curPos.first+e.second.first, curPos.second+e.second.second);

        if(newPos.first<0 || newPos.first>=totalRows || newPos.second<0 || newPos.second>=totalCols){
            continue;
        }

        if(visited[newPos.first][newPos.second]|| board[newPos.first][newPos.second]!=word[wordIdx+1]){
            continue;
        }

        
        cout<<"Going "<<e.first<<'\n';
        // cout<<"Going "<<e.first<<".....\n";
        res = existHelper(board, word, newPos, wordIdx + 1, visited);
        if(res){
            break;
        }
    }

    visited[curPos.first][curPos.second] = false;
    cout<<"Returning\n";
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == word[0]) {
                cout << "============\n";
                bool res = existHelper(board, word, make_pair(row, col), 0, v);
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
    vector<vector<char>> board3 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    string word1 = "ABCB";
    string word2 = "a";
    string word3 = "ABCCED";

    cout << exist(board1, word1)<<'\n';
    cout << exist(board2, word2)<<'\n';
    cout << exist(board3, word3)<<'\n';

    return 0;
}