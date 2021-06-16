#include<bits/stdc++.h>

using namespace std;
void printVector(vector<int> &v){
    for(auto e: v){
        cout<<e<<' ';
    }
    cout<<'\n';
}
//rowIndex is 0-indexed
// means Pascal triangle's 2nd row actually means 3rd row
vector<int> getNthPascal(int rowIndex){
    if(rowIndex+1<=2){
        return vector<int>(rowIndex+1, 1);
    }

    vector<int> prev = {1,1}, cur(rowIndex+1, 0);
    
    cur[0]=1;
    cur[rowIndex]=1;

    for(int i=2; i<=rowIndex+1;i++){
            
        for(int j=1; j<i;j++){
            cur[j] = prev[j-1]+prev[j];
        }

        cur[i-1]=1;
        prev = cur;
    }

    return cur;
}

int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    vector<int> res = getNthPascal(n);
    printVector(res);
    return 0;
}