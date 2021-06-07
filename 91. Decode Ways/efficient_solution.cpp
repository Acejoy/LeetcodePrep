#include<bits/stdc++.h>

using namespace std;

int numDecodings(string s) {
    int* dpTable=(int*)calloc(s.size()+1, sizeof(int));
    dpTable[0]=1;

    dpTable[1]= s[0]=='0'?0:1;

    for(int i=2; i<=s.size();i++){
        int oneDigit = stoi(s.substr(i-1,1));
        int twoDigit = stoi(s.substr(i-2,2));

        if(oneDigit>=1 && oneDigit<=9){
            dpTable[i]+=dpTable[i-1];
        }

        if(twoDigit>=10 && twoDigit<=26){
            dpTable[i]+=dpTable[i-2];
        }
    }

    return dpTable[s.size()];
}

int main(){

    string encoded = "11106";
    cout<<numDecodings(encoded)<<'\n';
    return 0;

}