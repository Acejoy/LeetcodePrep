/*
In this question, we are using dynamic programming.
in the dp table , each index contains the max subarray sum with subarray ending at that index.
So now simply, we traverse and find the max sum from dp table.
*/
#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int max_sum=INT_MIN;
    
    int dp[n];
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        dp[i]=max(nums[i],dp[i-1]+nums[i]);
    }
    
    for(int i=0;i<n;i++){
        max_sum=max(max_sum,dp[i]);
    }
    
    return max_sum;
    
}

int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(v)<<'\n';
    return 0;
}