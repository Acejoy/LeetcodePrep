#include<bits/stdc++.h>

using namespace std;

void printVec(vector<int> &v) {
    for(auto e: v){
        cout<<e<<' ';
    }
    cout<<'\n';
}

static bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second>b.second;
}

vector<pair<int, int>> getSorted(unordered_map<int, int> &freqMap) {
    vector<pair<int, int>> v;
    
    for(auto& it: freqMap) {
        v.push_back(it);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    return v;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    
    for(auto e: nums){
        m[e]++;
    }
    
    vector<pair<int, int>> sortedVec = getSorted(m);
    vector<int> ans;
    
    for(int i=0; i<k; i++) {
        ans.push_back(sortedVec[i].first);
    }
    
    return ans;
    
}

int main(){

    vector<int> vec = {1,1,1,3,3,3,3,3,3,3,2,2,2,2,2,4,4,4,4};
    int num = 2;
    vector<int> ans = topKFrequent(vec, num);
    printVec(ans);
    return 0;
}