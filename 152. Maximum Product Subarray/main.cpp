/*
this question is very similar to leetcode 53. Max Subarray. But the solution is a bit diff.
because if we use the theory of 53's then following vector:
[-2,3,-4]'s output will be 3 whereas answer is 24.

Ao we keep track of 2 arrays one for maxValue and other for minValue. because there
is possibility that minValue[idx-1]*num[idx]> maxValue[idx-1]*nums[idx]. 
*/
#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
    vector<int> maxdp(nums.size(), 0);
    vector<int> mindp(nums.size(), 0);
    int maxP = INT_MIN;
    
    maxdp[0] = nums[0];
    mindp[0] = nums[0];
    
    for(int i=1; i<nums.size(); i++) {
        maxdp[i] = max(nums[i], max(nums[i]*maxdp[i-1],nums[i]*mindp[i-1]));
        mindp[i] = min(nums[i], min(nums[i]*mindp[i-1], nums[i]*maxdp[i-1]));
    }
    
    for(int i=0; i<nums.size(); i++) {
        maxP = max(maxP, maxdp[i]);
    }
    
    return maxP;
}

int main(){
    
    vector<int> v = {2,3,-2,4};
    cout<<maxProduct(v)<<'\n';
    return 0;
}