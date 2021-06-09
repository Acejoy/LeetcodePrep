#include<bits/stdc++.h>

using namespace std;

void printSubsets(vector<vector<int>> v){
    for(auto subset:v){
        for(auto element: subset) {
            cout<<element<<' ';
        }
        cout<<'\n';
    }

    cout<<"\n\n";
}
vector<vector<int>> subsetHelper(vector<int>& nums, int idx){
    if(idx==nums.size()){
        return {{}};
    } else {
        vector<vector<int>> curSubset = {{}, {nums[idx]}};
        vector<vector<int>> restSubset = subsetHelper(nums, idx+1);
        vector<vector<int>> res;
        
        //merging
        for(auto e1: curSubset){                
            for(auto e2: restSubset){
                vector<int> v(e1.begin(), e1.end());
                v.insert(v.end(),e2.begin(),e2.end());
                res.push_back(v);
            }
        }
        return res;
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    return subsetHelper(nums, 0);
}

int main(){
    vector<int> ques = {1,2,3};
    vector<vector<int>> res = subsets(ques);
    printSubsets(res);
    return 0;
}