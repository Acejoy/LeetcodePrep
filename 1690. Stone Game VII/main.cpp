// Like most of the Stone Game problems, this one boils down to a system of ever-repeating 
// subproblems, as the there are many different ways to get to the same board condition as 
// we move towards the end of the game. This naturally points to a dynamic programming (DP) 
// solution.

// In order to represent the different board positions, we'd normally build an N * N DP matrix
// where N is the length of the stones array (S). In this DP array, dp[i][j] would represent 
// the best score difference with i representing the leftmost remaining stone's index and 
// j representing the rightmost remaining stone's index.

// Since we're using a top-down DP approach, we'll start at i = N - 2 and iterate backwards 
// and start each nested for loop at j = i + 1. This ensures that we're building the pyramid 
// of DP results downward, always starting each row with i and j next to each other.

// For each row, we'll keep track of the sum total of the stones in the range [i,j] by adding 
// S[j] at each iteration of j. Then, we can represent the current player's ideal play by 
// choosing the best value between picking the stone at i (total - S[i]) and picking the 
// stone at j (total - S[j]). For each option, we have to also subtract the best value that 
// the other player will get from the resulting board position (dp[i+1][j] or dp[i][j-1]).

// Since we will only be building off the current and previously-finished rows, however, 
// we can actually eliminate the DP matrix and instead just define two N-length arrays 
// representing the current and previous rows (dpCurr, dpLast), and swap between them at 
// each iteration of i. This will drop the space complexity from O(N^2) to O(N).

// At the end, the solution will be the value stored in the DP array representing the board 
// position with all stones present. We should therefore return dpCurr[N-1].

//     Time Complexity: O(N^2) where N is the length of S
//     Space Complexity: O(N) for the two dp arrays

// the link is : https://dev.to/seanpgallivan/solution-stone-game-vii-3lei

#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    for (auto e : v) {
        cout << e << ' ';
    }

    cout << '\n';
}

int stoneGameVII(vector<int>& stones) {    
    
    int N = stones.size();
    vector<int> dpCurr(N), dpLast(N);
    for (int i = N - 2; ~i; i--) {
        cout<<i<<":\n";
        int total = stones[i];
        dpLast.swap(dpCurr);
        for (int j = i + 1; j < N; j++) {
            total += stones[j];
            dpCurr[j] = max(total - stones[i] - dpLast[j], total - stones[j] - dpCurr[j-1]);
        }
        printVector(dpCurr);
        printVector(dpLast);
        cout<<'\n';
    }
    return dpCurr[N-1];
}

int main(){

    vector<int> ques ={5,3,1,4,2};
    cout<<stoneGameVII(ques)<<'\n';

    return 0;
}