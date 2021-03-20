//time complexity - O(n)
//space complexity - O(1)

#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int> &arr) {
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<' ';
	}
	cout<<"\n---------------------------\n";
}

bool getNextPermutation(vector<int> &nums) {
    bool flag = false;
    int temp;
    
    for(int i=nums.size()-2; !flag && i>=0; i--) {
        if(nums[i]>=nums[i+1]) {
            flag = false;
        } else {
            //finding the element just greater than the current element in array
            // from index (i+1) till end
            int j=nums.size()-1;
            while(j>i) {
                if(nums[i]<nums[j]) {
                    break;
                }
                j--;
            }
            
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            
            sort(nums.begin()+(i+1), nums.end());
            flag = true;
        }
    }
    
    return flag;
}
void nextPermutation(vector<int>& nums) {
    bool flag = getNextPermutation(nums);
    
    if(flag==false) {
        sort(nums.begin(), nums.end());
    }
}

int main() {

	vector<int> arr;
	int n, num;
	cout<<"enter no of numbers:";
	cin>>n;

	cout<<"enter array:";
	for(int i=0; i<n; i++) {
		cin>>num;
		arr.push_back(num);
	}

	printArray(arr);
	nextPermutation(arr);
	printArray(arr);

	return 0;
}