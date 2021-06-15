// in this question, we write a recursive function, where index refers to current 
// matchstick. we need to partition the matchsticks set into 4 sets, one for each side.
// We are doing DFS traversal for each matchstick.
#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<int>& nums, vector<int>& sums, int idx, int target){
    if(idx==nums.size()){
        return sums[0]==target && sums[1]==target && sums[2]==target;
    } else {
        for(int i=0; i<4; i++){
            if(sums[i]+nums[idx]>target){
                continue;
            }
            
            int j = i;
            while (--j >= 0) // third
                if (sums[i] == sums[j]) 
                    break;
            if (j != -1) continue;
            
            
            sums[i]+=nums[idx];
            
            
            
            if(dfs(nums, sums, idx+1, target)){
                return true;
            }
            sums[i]-=nums[idx];
        }
        
        return false;
    }
}    

bool makesquare(vector<int>& matchsticks) {
    if(matchsticks.size()<4){
        return false;
    }
    
    int sum=0;
    for(auto e: matchsticks){
        sum+=e;
    }
    
    if(sum%4!=0){
        return false;
    }
    
    vector<int> fourSums(4,0);
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    return dfs(matchsticks, fourSums, 0, sum/4);        
}

int main(){
    vector<int> ques = {1,1,2,2,2};
    cout<<makesquare(ques)<<'\n';
    return 0;
}