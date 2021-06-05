/*
find the starting point in the rotated array, then binary search in the two subArrays,
that are [startingIdx, lastindx] and [0, startingIdx-1].
*/
#include<bits/stdc++.h>

using namespace std;

int getMinIdx(vector<int>& nums, int leftLimit, int rightLimit) {
    if(leftLimit<=rightLimit) {
        int mid = leftLimit +(rightLimit-leftLimit)/2; 

        if(mid!=(nums.size()-1) && nums[mid]>nums[mid+1]) {
            return mid+1;
        } else {
            //mid element is greater than leftLimit so [leftLimit, mid]
            //is sorte, so smallest element is in [mid+1, rightLimit].
            if(nums[mid]>=nums[leftLimit]){
                return getMinIdx(nums, mid+1, rightLimit);
            } else {
                return getMinIdx(nums, leftLimit, mid-1);
            }
        }
    }

    return -1;
}    

int binSearch(vector<int>& nums, int leftLimit, int rightLimit, int target){
    if(leftLimit==rightLimit){
        if(nums[leftLimit]==target){
            return leftLimit;
        } else {
            return -1;
        }
    } 

    if(leftLimit<rightLimit) {
        int mid = leftLimit + (rightLimit-leftLimit)/2;
        
        if(nums[mid]==target) {
            return mid;
        } else {
            if(nums[mid]>target) {
                return binSearch(nums, leftLimit, mid-1, target);
            } else {
                return binSearch(nums, mid+1, rightLimit, target);
            }
        }
    }
    
    return -1;
}

int search(vector<int>& nums, int target) {
    if(nums.size()==0) {
        return -1;
    } else if(nums.size()==1) {
        if(nums[0]==target) {
            return 0;
        } else {
            return -1;
        }
    } else {
        int minIdx ;
        if(nums[0]<nums[nums.size()-1]){
            minIdx = 0;
        } else {
            minIdx = getMinIdx(nums, 0, nums.size()-1);
        }

        cout<<"The minIdx is "<<minIdx<<'\n';
        
        if(nums[minIdx]<=target && target<=nums[nums.size()-1]) {
            return binSearch(nums, minIdx, nums.size()-1, target);
        } else {
            return binSearch(nums, 0, minIdx-1, target);
        }
    }
}

int main(){
    vector<int> v = {4,5,6,7,0,1,2};
    int target = 0;

    cout<<search(v, target)<<'\n';
    return 0;
}