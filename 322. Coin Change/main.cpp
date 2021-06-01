#include<bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount){

    vector<int> changeTable(amount+1, 0);

    for(int i=1; i<=amount; i++){
        int minCoinsReqd = INT_MAX;

        for(auto coinVal: coins){
            if(coinVal>i){
                continue;
            } else {
                if(changeTable[i-coinVal] == INT_MAX) {
                    continue;
                }
                
                minCoinsReqd = min(1+changeTable[i-coinVal], minCoinsReqd);
            }
        }

        changeTable[i]=minCoinsReqd;
    }
    
    if(changeTable[amount] == INT_MAX) {
        return -1;
    }
    
    return changeTable[amount];
}

int main(){

    int n, temp, val;
    vector<int> v;
    cout<<"Enter the number of coin types:";
    cin>>n;

    for(int idx=0; idx<n; idx++){
        cin>>temp;
        v.push_back(temp);
    }

    cout<<"Enter the value you want changed:";
    cin>>val;

    cout<<"Min coins required are:"<<coinChange(v, val)<<'\n';
    return 0;
}