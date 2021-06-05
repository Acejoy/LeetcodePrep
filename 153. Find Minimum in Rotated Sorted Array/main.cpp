/*
We are looking for the break i.e. mid element is greater than its right side.

*/
#include<bits/stdc++.h>

using namespace std;

int findMinHelper(vector<int>& nums, int leftLimit, int rightLimit) {
    if(leftLimit<=rightLimit) {
        int mid = leftLimit +(rightLimit-leftLimit)/2; 
        
        if(mid!=(nums.size()-1) && nums[mid]>nums[mid+1]) {
            return mid+1;
        } else {
            //mid element is greater than leftLimit so [leftLimit, mid]
            //is sorte, so smallest element is in [mid+1, rightLimit].
            if(nums[mid]>=nums[leftLimit]){
                return findMinHelper(nums, mid+1, rightLimit);
            } else {
                return findMinHelper(nums, leftLimit, mid-1);
            }
        }
    }
    
    return -1;
}

int findMin(vector<int>& nums) {
    
    if(nums.size()==1){
        return nums[0];
    }
    
    if(nums[0]<nums[nums.size()-1]){
        return nums[0];
    } else {
        return nums[findMinHelper(nums,0, nums.size()-1)];                
    }
}

int main(){
    vector<int> v = {4,5,6,7,0,1,2};
    cout<<findMin(v)<<'\n';
    return 0;
}