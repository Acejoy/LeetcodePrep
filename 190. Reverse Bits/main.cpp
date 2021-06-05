#include<bits/stdc++.h>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t newNum=0;
    int steps=0;
    
    while(steps<32){
        newNum=newNum<<1;
        newNum|=(n&1);
        n=n>>1;    
        steps++;
    }
    
    return newNum;
}

int main(){
    uint32_t num = 43261596;
    cout<<reverseBits(num)<<'\n';
    return 0;
}