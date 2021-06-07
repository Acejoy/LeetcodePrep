/*
alternate solution could have been simply uniquePaths(m,n):fact(m+n-2)/(fact(m)*fact(n))
*/
#include<bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n) {
    int dpTable[m][n];
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 ||j==0){
                dpTable[i][j]=1;
            } else{
                dpTable[i][j]=0;    
            }
        }
    }
    
    for(int i=1;i<m;i++){
        for(int j=1; j<n; j++){
            dpTable[i][j] = dpTable[i-1][j] +dpTable[i][j-1];
        }
    }
    
    return dpTable[m-1][n-1];
}

int main(){

    int rows = 3;
    int cols = 7;
    cout<<uniquePaths(rows, cols)<<'\n';
    return 0;
}