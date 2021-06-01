/*
The question link is: https://leetcode.com/problems/integer-break/submissions/
The solution is simple dynamic Programming

intBreak of 5:
max of all below:
1xmax(4, intbreak(4))   2xmax(3, intbreak(3))   3xmax(2, intbreak(2))   4xmax(1, intbreak(1))


we can memoise the results by storing it in a table.
*/
#include<bits/stdc++.h>

using namespace std;

int helperfn(int n, vector<int>& memoisation) {
    
    int maxProd =0;
    
    if(n==2){
        memoisation[2]=1;
        maxProd=1;
    } else {
        for(int i=1; i<=n-1; i++) {
            if(memoisation[n-i] == 0 && (n-i)!=1) {
                helperfn(n-i, memoisation);
            }
            
            maxProd = max(maxProd, max(i*(n-i),i*memoisation[n-i]));
        }
    }
    
    memoisation[n]=maxProd;
    cout<<"max prod of "<<n<<" is:"<<maxProd<<'\n';
    return maxProd;
}

int integerBreak(int n) {
        
    vector<int> v(59,0);
    int reqAns = helperfn(n, v);
    
    return reqAns;
}

int main(){

    int m = integerBreak(10);
    return 0;
}