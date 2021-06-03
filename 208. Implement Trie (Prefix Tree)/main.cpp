#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    bool EOW = false;        
    map<char, Trie*> charMap;
    
    Trie() {
            
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curNode = this;
        map<char, Trie*>::iterator temp;
        
        for(auto c: word) {
            temp = curNode->charMap.find(c);    
            
            if(temp!=curNode->charMap.end()){
                curNode = temp->second;
            } else {
                curNode->charMap[c] = new Trie();
                curNode = curNode->charMap[c] ;
            }
        }
        
        curNode->EOW = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curNode = this;
        map<char, Trie*>::iterator temp;
        
        for(auto c: word) {
            temp = curNode->charMap.find(c);    
            
            if(temp!=curNode->charMap.end()){
                curNode = temp->second;               
            } else {
                return false;
            }
        }
        
        return curNode->EOW;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curNode = this;
        map<char, Trie*>::iterator temp;
        
        for(auto c: prefix) {
            temp = curNode->charMap.find(c);    
            
            if(temp!=curNode->charMap.end()){
                curNode = temp->second;               
            } else {
                return false;
            }
        }
        
        return true;
    }
};

int main(){

    Trie* obj = new Trie();
    obj->insert("Hello");
    bool param_2 = obj->search("Hello");
    bool param_3 = obj->startsWith("Hell");

    cout<<param_2<<' '<<param_3<<'\n';
    return 0;
}