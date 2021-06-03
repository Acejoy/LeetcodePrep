/*
Same as Trie, just a different search function for this functionality-
if word contains '.' character, it should match with any character just like in regular expression.
*/
#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    bool EOW = false;        
    map<char, WordDictionary*> charMap;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary* curNode = this;
        map<char, WordDictionary*>::iterator temp;
        
        for(auto c: word) {
            temp = curNode->charMap.find(c);    
            
            if(temp!=curNode->charMap.end()){
                curNode = temp->second;
            } else {
                curNode->charMap[c] = new WordDictionary();
                curNode = curNode->charMap[c] ;
            }
        }
        
        curNode->EOW = true;    
    }
    
    bool search(string word) {
        return searchHelperFn(word, this, 0);;
    }
    
    bool searchHelperFn(string word, WordDictionary* curNode, int index) {
        if(index==word.size()){
            return curNode->EOW;
        } else {
            if(word[index]=='.'){
                bool temp;
                for(auto e: curNode->charMap){
                    temp = searchHelperFn(word, e.second, index+1);
                    
                    if(temp){
                        return true;
                    }
                }
                
                return false;
                
            } else {
                map<char, WordDictionary*>::iterator it = curNode->charMap.find(word[index]);
                
                if(it==curNode->charMap.end()){
                    return false;
                } else {
                    curNode= curNode->charMap[word[index]];
                    return searchHelperFn(word, curNode, index+1);                    
                }
            }
        }
    }
};


int main() { 
    
    WordDictionary* obj = new WordDictionary();
    obj->addWord("hello");
    bool param_2 = obj->search("hel..");
    cout<<param_2<<'\n';
    return 0;
}