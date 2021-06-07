#include<bits/stdc++.h>

using namespace std;

int numDecodings(string s) {
    int prev2DpVal = 1;
    int prevDpVal = s[0]=='0'?0:1;
    int temp=0;

    for(int i=2; i<=s.size();i++){
        temp=0;
        int oneDigit = stoi(s.substr(i-1,1));
        int twoDigit = stoi(s.substr(i-2,2));

        if(oneDigit>=1 && oneDigit<=9){
            temp+=prevDpVal;
        }

        if(twoDigit>=10 && twoDigit<=26){
            temp+=prev2DpVal;
        }

        prev2DpVal = prevDpVal;
        prevDpVal = temp;        
    }

    return prevDpVal;
}

int main(){

    string encoded = "11106";
    cout<<numDecodings(encoded)<<'\n';
    return 0;

}