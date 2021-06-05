#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
    int total_xor = 0;
    int input_xor=0;
    
    for(int i=0; i<=nums.size(); i++) {
        total_xor ^= i;
    }
    
    for(int i=0; i<nums.size(); i++){
        input_xor^=nums[i];
    }
    
    return total_xor^input_xor;
}

int main(){
    vector<int> ans ={9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(ans)<<'\n';
    return 0;
}