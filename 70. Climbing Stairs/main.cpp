#include<bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    int* arr = (int*)calloc(n+1, sizeof(int)) ;
    arr[0]=1;
    for(int i=1;i<=n;i++){
        arr[i] += arr[i-1];
        
        if(i!=1){
            arr[i] += arr[i-2];
        }
    }
    
    return arr[n];
}

int main(){
    int n=2;
    cout<<climbStairs(n)<<'\n';
    return 0;
}