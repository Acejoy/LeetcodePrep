#include<bits/stdc++.h>

using namespace std;

void printAns(vector<vector<int>> &v){
    for(auto e:  v){
        cout<<'['<<e[0]<<','<<e[1]<<']'<<' ';
    }

    cout<<'\n';
}

bool checkPalindrome(string word){
    if(word==""){
        return true;
    } else {
        int leftPtr=0;
        int rightPtr=word.size()-1;
        
        while(leftPtr<rightPtr){
            if(word[leftPtr]!=word[rightPtr]){
                return false;
            }
            leftPtr++;
            rightPtr--;                
        }
        
        return true;
    }
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    map<string, int> wordMap;
    string part1, part2;
    bool check1, check2;
    //filling the map
    
    for(int i=0; i<words.size(); i++){
        wordMap.insert({words[i], i});
    }

    for(int i=0; i<words.size(); i++){
        
        for(int idx=0; idx<words[i].size(); idx++){
            part1=words[i].substr(0, idx+1);
            part2=words[i].substr(idx+1, string::npos);
            cout<<part1<<':'<<part2<<":\n";

            check1 = checkPalindrome(part1);
            check2 = checkPalindrome(part2);

            reverse(part1.begin(), part1.end());
            reverse(part2.begin(), part2.end());
            cout<<part1<<':'<<part2<<":\n";

            if(check1 && wordMap.find(part2) !=wordMap.end() && wordMap[part2]!=i){
                if(part2==""){
                    ans.push_back({i, wordMap[part2]});    
                }
                ans.push_back({wordMap[part2], i});    
            }

            if(check2 && wordMap.find(part1) !=wordMap.end() && wordMap[part1]!=i){
                if(part1==""){
                    ans.push_back({wordMap[part1], i});    
                }
                ans.push_back({i, wordMap[part1]});    
            }

        }
    }
    
    return ans;
}

int main(){
    vector<string> ques1 = {"abcd","dcba","lls","s","sssll"};
    vector<string> ques2 = {"a", ""};
    vector<vector<int>> ans = palindromePairs(ques1);
    printAns(ans);
    return 0;
}