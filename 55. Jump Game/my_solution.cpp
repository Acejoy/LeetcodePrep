/*
dpTable[idx] = stores whether it is possible to reach last place from idx.
*/
#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums) {
    bool dpTable[nums.size()];
    dpTable[nums.size()-1]=true;
    
    for(int idx=nums.size()-2; idx>=0; idx--) {
        int val = nums[idx];
        
        dpTable[idx]=false;
        for(int i=1; i<=val; i++) {
            if((i+idx)<nums.size() && dpTable[i+idx]){
                dpTable[idx]=true;
                break;
            }
        }
    }
    
    return dpTable[0];
}

int main(){
    vector<int> ques = {2,3,1,1,4};
    cout<<canJump(ques)<<'\n';
    return 0;
}