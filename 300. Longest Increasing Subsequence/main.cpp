/*
In this question, we use Dynamic Programming
we create a vector which stores the maximum length subsequence ending at that index, initialise
it to 1(refering to the number itself).now we start from i=second index and look for
smaller elements in subarray[0, i-1].the formula used is
ans[i] = max(ans[i], ans[j]+1)  , ans[j]+1 refers to length of subsequence at jth index(j<i) plus itself.

*/
#include<bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> ans(nums.size(),1);
    int j=0, maxLengthSubsq=INT_MIN;
    
    for(int i=1; i<nums.size(); i++){
        
        j=0;            
        while(j<i){
            if(nums[j]<nums[i]){
                ans[i] = max(ans[i], ans[j]+1);
            }
            j++;
        }
    }
    
    for(auto e: ans){
        maxLengthSubsq = max(maxLengthSubsq, e);
    }
    return maxLengthSubsq;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<'\n';
    return 0;
}