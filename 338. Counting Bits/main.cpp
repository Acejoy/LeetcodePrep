#include<bits/stdc++.h>

using namespace std;

void printArray(vector<int>& v) {
    for(auto e: v){
        cout<<e<<' ';
    }
    cout<<'\n';
}

vector<int> countBits(int n) {
    vector<int> ans(n+1, 0);
    int ones=0, temp;
    
    for(int i=0; i<=n; i++) {
        ones=0;
        temp=i;
        
        while(temp){
            (temp&1)?ones++:0;
            temp = temp>>1;
        }
        
        ans[i]=ones;
    }
    
    return ans;
}

int main(){
    vector<int> ans = countBits(10);
    printArray(ans);
    return 0;
}