#include<bits/stdc++.h>

using namespace std;

set<string> reverseMap;

int numDecodingsHelper(string s, map<string, int>& cache){
    if(cache.find(s)!=cache.end()){
        return cache[s];
    } else {
        int decodings=0;        

        for(int len=1; len<=s.size() && len<=2; len++) {
            string subWord = s.substr(0,len);
            string rest = s.substr(len,s.size()-1);

            if(reverseMap.find(subWord)!=reverseMap.end()){
                if(rest==""){
                    decodings +=1;
                } else{
                    decodings += numDecodingsHelper(rest,cache);
                }                
            }
            
        }
        cout<<s<<' '<<decodings<<'\n';
        cache.insert({s, decodings});
        return decodings;
    }
    
    cache.insert({s,0});
    return 0;
}

int numDecodings(string s) {
    for(int i=0; i<26;i++){
        reverseMap.insert(to_string(i+1));
    }

    // reverseMap.insert({"",})
    
    map<string, int> stringDecodings;
    return numDecodingsHelper(s, stringDecodings);
}

int main(){
    string encoded =  "11106";
    cout<<numDecodings(encoded)<<'\n';
    return 0;
}