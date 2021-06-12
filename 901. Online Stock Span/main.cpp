#include<bits/stdc++.h>

using namespace std;

stack<pair<int,int>> stockSt;
int size;

int next(int price) {
    int res;
    while(!stockSt.empty() && stockSt.top().second<=price){            
        stockSt.pop();
    }
    
    if(stockSt.empty()){
        res = size+1;
    } else {
        res = size +1 - stockSt.top().first;
    }        
    
    stockSt.push(make_pair(size+1,price));
    size++;
    
    return res;
}

int main(){

    vector<int> ques ={100, 80, 60, 70, 60, 75, 85};
    for(auto e: ques){
        cout<<next(e)<<'\n';
    }

    return 0;
}