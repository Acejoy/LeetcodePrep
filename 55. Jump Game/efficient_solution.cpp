/*
here we use reach variable to keep in mind the highest index  and
see if it is >= than last index
*/
#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums) {
    int reach=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(i>reach)
        {
            return false;
        }
        if(reach>=n-1)
        {
            return true;
        }
        reach=max(reach,i+nums[i]);
    }
    
    return true;
}

int main(){
    vector<int> ques = {2,3,1,1,4};
    cout<<canJump(ques)<<'\n';
    return 0;
}