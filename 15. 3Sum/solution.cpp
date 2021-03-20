#include<bits/stdc++.h>

using namespace std;

void printTriplets(vector<vector<int>> &v) {

	for(int i=0; i<v.size(); i++) {
		cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
	}
}

void printArray(vector<int> &A) {

	for (int i=0; i<A.size(); i++) {
		printf("%5d ", A[i]);
	}

	cout<<endl;
}

vector<vector<int>> threeSum(vector<int>& nums) {
 
    vector<vector<int>> ans;
    
    if (nums.size()>2) {
        
        //set<int> hashTable;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2; i++) {
            
            // Never let i refer to the same value twice to avoid duplicates.
            if (i != 0 && nums[i] == nums[i - 1]){ 
                continue;
            }
            
            int leftIdx = i+1;
            int rightIdx = nums.size()-1;
            
            while(leftIdx < rightIdx) {
                
                int partialSum = nums[leftIdx]+nums[rightIdx];
                
                if(partialSum +nums[i] == 0) {
                    
                    vector<int> v{nums[i], nums[leftIdx], nums[rightIdx]};
                    ans.push_back(v);
                    leftIdx++;
                    rightIdx--;
                    // Never let j refer to the same value twice (in an output) to avoid duplicates
                    while (leftIdx < rightIdx && nums[leftIdx] == nums[leftIdx-1]){ 
                        leftIdx++;
                    }
                    
                } else if(partialSum +nums[i] < 0) {
                    
                    leftIdx++;
                    
                } else {
                   
                    rightIdx--;
                    
                }
            }
        }   
        
    }
    
    return ans;
}

int main() {

	vector<int> v{-1,0,1,2,-1,-4};
	vector<vector<int>> a= threeSum(v); 
	printTriplets(a);
	return 0;
}