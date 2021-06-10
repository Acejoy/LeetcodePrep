#include<bits/stdc++.h>

using namespace std;

int maxResult(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(nums[0], 0));

    pair<int,int> maxCell;

    for(int i=1; i<nums.size(); i++){

        maxCell = pq.top();        

        while(!pq.empty() && maxCell.second+k<i){
            pq.pop();
            maxCell = pq.top();

        }

        nums[i]+=maxCell.first;

        pq.emplace(make_pair(nums[i],i));
        cout<<i<<' '<<nums[i]<<'\n';

    }

    return nums[nums.size()-1];
}

int main(){

    vector<int> ques1 = {2,1,-1,-2,4,-7,3};
    vector<int> ques2 = {100,-1,-100,-1,100};
    int k=2;
    cout<<maxResult(ques2,k)<<'\n';
    return 0;
}