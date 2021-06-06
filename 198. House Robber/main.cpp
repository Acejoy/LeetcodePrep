/*
 Solve the problem for simpler cases to help us solve the larger problem at hand 
 (this is the idea of bottom-up processing). Create a dp array where dp[i] will 
 represent the max amount of money we can rob up to and including the current house. 
 First fill the simple cases, or base cases, of the dp array 
 like dp[0] = nums[0] (the most amount of money we can rob up to the first house is 
 however much money is in the first house, dp[1] = max of num[0] and nums[1] 
 (we can't rob both because of the alarm systems so rob whichever house has more money). 
 Then iterate through the rest of the dp array populating dp[i] at every iteration using 
 the follow logic...dp[i] = max of robbing the current house and however much money we had 
 2 houses before, or simply continue on with the max amount of money we had robbed up to 
 the previous house. Once you have populated the dp array simply return the last entry  which 
 represents the max amount of money you can rob from all the houses without triggering the alarm system.
*/
#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v){
    for(auto e: v){
        cout<<e<<' ';
    }
    cout<<'\n';
}

int rob(vector<int>& nums) {
    
    vector<int> dpTable(nums.size(), 0);
    dpTable[0] =nums[0];
    
    if(nums.size()>1){
        
        dpTable[1]=max(nums[1], nums[0]);       
        
        for(int i=2; i<nums.size();i++) {
            dpTable[i] = max(dpTable[i-1], nums[i]+dpTable[i-2]);
        }           
        
    }
    
    printVector(dpTable);
    return dpTable[nums.size()-1];
}

int main(){

    vector<int> v = {1,2,3,1};
    cout<<rob(v)<<'\n';
    return 0;
}