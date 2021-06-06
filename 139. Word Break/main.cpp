/*
In this question, first we iterate through each word of dict to see if the word can break the
given word , if yes, we call the wordBreak function on the string left after macthing the word.
Also we store result each of string that can/cannot be broken.
*/
#include<bits/stdc++.h>

using namespace std;

bool wordBreakHelper(string s, vector<string>& wordDict, map<string, int>& wordMap){
        
    if(wordMap.find(s)!=wordMap.end()){
        return wordMap[s];
    }

    vector<string>::iterator it=find(wordDict.begin(), wordDict.end(), s);
    if(it!=wordDict.end()){
        return true;
    }


    for(auto word: wordDict){
        if(word.size()>s.size()){
            continue;
        } else {
            string subWord = s.substr(0, word.size());
            int restString = s.size()-word.size();
            if(subWord==word && wordBreakHelper(s.substr(word.size(),restString), wordDict, wordMap)) {

                wordMap.insert({s, true});
                return true;
            } 
        }
    }

    wordMap.insert({s, false});
    return false;
    
}

bool wordBreak(string s, vector<string>& wordDict) {
    map<string, int> wordMap;
    return wordBreakHelper(s, wordDict, wordMap);
}

int main(){

    string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string s2 = "aaaaaaaa";
    vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    cout<<wordBreak(s1, dict)<<'\n';

    return 0;
}