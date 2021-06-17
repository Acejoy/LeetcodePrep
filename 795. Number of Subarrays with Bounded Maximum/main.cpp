// The key to this problem is realizing that we're dealing with overlapping triangular number 
// issues. Importantly, the total number of possible subarrays that are contained within any 
// larger subarray is the Nth triangular number, where N is the length of that larger subarray.
// So the nums array starts with the (nums.length)th triangular number total subarrays. 
// We want to exclude any subarray that includes a number larger than right, however. 
// The easiest way to do this is to consider numbers larger than right to be dividers, 
// splitting nums into many subarrays. We can add the triangular number for each of these 
// resulting subarrays together to be the total number of subarrays that exclude numbers 
// higher than right.

// To do this, we can iterate through nums and keep track of how many contiguous numbers are 
// less than right (mid) and each point that mid increments, we can add mid to ans, representing
// the increase to the next triangular number. The value for mid will then reset whenever we see a 
// number higher than right.

// But this only does half of the problem, because we still have to also exclude any subarray 
// that does not have any number at least left high. To do this, we can use a similar method 
// as for mid. We can keep track of how many contiguous numbers are lower than left (low) and 
// decrease ans by that amount every time it increments, representing the next triangular 
// number. Similar to mid, low will reset whenever we see a number at least left high.
// Once we're done iterating, we can return ans.

#include<bits/stdc++.h>

using namespace std;

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int ans=0, lowerThanLeft=0, lowerThanRight=0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]>right){
            lowerThanRight=0;
        } else {
            ans += ++lowerThanRight;
        }

        if(nums[i]>=left){
            lowerThanLeft=0;
        } else {
            ans -= ++lowerThanLeft;
        }
    }

    return ans;
}


int main(){
    vector<int> ques = {2,1,4,3};
    int left=2, right=3;
    cout<<numSubarrayBoundedMax(ques, left, right);
    return 0;
}