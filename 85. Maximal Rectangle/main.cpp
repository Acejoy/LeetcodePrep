#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    for (auto e : v) {
        cout << e << ' ';
    }

    cout << '\n';
}

int maxAreaRectangle(vector<int>& hist) {
    vector<int> leftLimit, rightLimit(hist.size(), 0);
    stack<int> st;

    int maxArea = INT_MIN, area;

    // left limits calc
    for (int i = 0; i < hist.size(); i++) {
        if (st.empty()) {
            leftLimit.push_back(0);
        } else {
            while (!st.empty() && hist[st.top()] >= hist[i]) {
                st.pop();
            }

            if (st.empty()) {
                leftLimit.push_back(0);
            } else {
                leftLimit.push_back(st.top()+1);
            }
        }

        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    // left limits calc
    for (int i = hist.size() - 1; i >= 0; i--) {
        if (st.empty()) {
            rightLimit[i] = hist.size() - 1;
        } else {
            while (!st.empty() && hist[st.top()] >= hist[i]) {
                st.pop();
            }

            if (st.empty()) {
                rightLimit[i] = hist.size() - 1;
            } else {
                rightLimit[i] = st.top()-1;
            }
            
        }

        st.push(i);
    }

    for (int i = 0; i < hist.size(); i++) {
        area = hist[i] * (rightLimit[i] - leftLimit[i] + 1);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }

    int maxAreaRow = INT_MIN;
    vector<int> rowHist(matrix[0].size(), 0);

    for (int rowIdx = 0; rowIdx < matrix.size(); rowIdx++) {
        for (int colIdx = 0; colIdx < matrix[0].size(); colIdx++) {
            if (matrix[rowIdx][colIdx] == '0') {
                rowHist[colIdx] = 0;
            } else {
                rowHist[colIdx] += (matrix[rowIdx][colIdx] - '0');
            }            
        }

        printVector(rowHist);
        maxAreaRow = max(maxAreaRow, maxAreaRectangle(rowHist));
    }

    return maxAreaRow;
}

int main() {
    vector<vector<char>> ques = {
        { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' }
    };

    cout<<maximalRectangle(ques)<<'\n';
    return 0;
}