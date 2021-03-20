#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> &A) {

	for (int i=0; i<A.size(); i++) {
		printf("%5d ", A[i]);
	}

	cout<<endl;
}

int findStartingIdx(vector<int>& nums, int target, int leftLimit, int rightLimit) {
	//cout<<"ll:"<<leftLimit<<", rl:"<<rightLimit;
    if(leftLimit<=rightLimit) {
        int mid = leftLimit +(rightLimit-leftLimit)/2;
        //cout<<", mid:"<<mid<<endl;
        if(nums[mid]==target && ((mid!=0 && nums[mid-1]!=target) || mid==0)) {
            return mid;
        } else if((nums[mid]>target) || (mid!=0 && nums[mid-1]==target)) {
            return findStartingIdx(nums, target, leftLimit, mid-1);
        } else {
            return findStartingIdx(nums, target, mid+1, rightLimit);
        }
    }
    
    return -1;
}

int findEndingIdx(vector<int>& nums, int target, int leftLimit, int rightLimit) {
	//cout<<"ll:"<<leftLimit<<", rl:"<<rightLimit;

    if(leftLimit<=rightLimit) {
        int mid = leftLimit +(rightLimit-leftLimit)/2;
        //cout<<", mid:"<<mid<<endl;
        if(nums[mid]==target && ((mid!=nums.size()-1 && nums[mid+1]!=target) || mid==nums.size()-1)) {
            return mid;
        } else if((nums[mid]<target) || (mid != nums.size()-1 && nums[mid+1]==target)) {
            return findEndingIdx(nums, target, mid+1, rightLimit);
        } else {
            return findEndingIdx(nums, target, leftLimit, mid-1);
        }
    }
    
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.push_back(findStartingIdx(nums, target, 0, nums.size()-1));
    ans.push_back(findEndingIdx(nums, target, 0, nums.size()-1));
    
    return ans;
}

int main() {

	int n,k, num;
	cout<<"enter size:";
	cin>>n;
	cout<<"target?:";
	cin>>k;

	vector<int> v;

	for(int i=0; i<n;i++) {
		cin>>num;
		v.push_back(num);
	}

	printArray(v);
	vector<int> ans = searchRange(v, k);
	cout<<ans[0]<<' '<<ans[1]<<endl;
	return 0;
}