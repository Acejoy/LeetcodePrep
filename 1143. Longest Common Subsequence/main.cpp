#include<bits/stdc++.h>

using namespace std;

void printVector(vector<vector<int>> v){
    for(auto row: v){
        for(auto e: row){
            cout<<e<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

vector<vector<int>> longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dpTable(text1.size()+1, vector<int> (text2.size()+1, 0));

    printVector(dpTable);
    
    for(int i=1; i<=text1.size(); i++) {
        for(int j=1; j<=text2.size(); j++) {
            
            dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
            //we are using i-1 and j-1 here
            //because string is 0 indexed and we are starting i and 
            //j from 1.(1-indexed).
            if(text1[i-1]==text2[j-1]){
                // cout<<text1[i-1]<<' '<<text2[j-1]<<'\n';
                dpTable[i][j] = max(1+dpTable[i-1][j-1], dpTable[i][j]);
            }

            // cout<<i<<' '<<j<<' '<<dpTable[i][j]<<'\n';
        }
    }
    
    // return dpTable[text1.size()][text2.size()];        
    return dpTable;
}

int main(){
    string t1 = "abc";
    string t2 = "def";

    vector<vector<int>> v = longestCommonSubsequence(t1, t2);
    printVector(v);
    return 0;
}