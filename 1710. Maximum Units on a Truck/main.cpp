#include<bits/stdc++.h>

using namespace std;

bool customCmp(vector<int>& v1, vector<int>& v2){
    return v1[1]>v2[1];
}

void printV(vector<vector<int>> &box){
    for(auto e: box){
        cout<<e[0]<<' '<<e[1]<<'\n';
    }

    cout<<'\n';
}
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), customCmp);
    printV(boxTypes);
    int sizeLeft = truckSize, unitsPut = 0, curIdx = 0;

    while(sizeLeft>0 && curIdx<boxTypes.size()){
        if(sizeLeft>boxTypes[curIdx][0]){
            unitsPut+=boxTypes[curIdx][0]*boxTypes[curIdx][1];
            sizeLeft-=boxTypes[curIdx][0];
        } else {
            unitsPut+=sizeLeft*boxTypes[curIdx][1];
            sizeLeft=0;
        }
        curIdx++;
    }

    return unitsPut;
}

int main(){
    int fullSize1 = 4;
    vector<vector<int>> ques1 ={{1,3},{2,2},{3,1}};
    
    int fullSize2 = 10;
    vector<vector<int>> ques2 ={{5,10},{2,5},{4,7}, {3,9}};
    
    cout<<maximumUnits(ques2, fullSize2)<<'\n';
    return 0;   
}