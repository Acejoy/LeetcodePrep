#include<bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for(auto e: nums) {
        if(s.find(e)!=s.end()) {
            return true;
        } else {
            s.insert(e);
        }
    }
    
    return false;
}

int main(){

    vector<int> v = {1,2,3,1};
    cout<<containsDuplicate(v)<<'\n';
    return 0;
}