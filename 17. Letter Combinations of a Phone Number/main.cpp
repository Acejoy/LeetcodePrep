#include<bits/stdc++.h>

using namespace std;

string mappings[8]={
    string("abc"),
    string("def"),
    string("ghi"),
    string("jkl"),
    string("mno"),
    string("pqrs"),
    string("tuv"),
    string("wxyz")
};

void printVector(vector<string> &v){
    for(auto s: v){
        cout<<s<<' ';
    }
    cout<<'\n';
}

vector<string> letterComboHelper(string digits){

    vector<string> curEncodings;

    if(digits !=""){
        string letters= mappings[digits[0]-'0'-2];
        vector<string> restEncodings = letterComboHelper(digits.substr(1,digits.size()-1));

        for(auto c: letters){
            for(auto e: restEncodings){
                curEncodings.push_back(c+e);
            }
        }

    } else {
        curEncodings.push_back("");
    }

    return curEncodings;
}

vector<string> letterCombinations(string digits) {
    if(digits==""){
        return {};
    }

    return letterComboHelper(digits);
}

int main(){

    vector<string> ques = {"23", "", "2"};

    for(auto s: ques){
        vector<string> res = letterCombinations(s);
        cout<<"============================\n"<<s<<":\n";
        printVector(res);

    }
    
    return 0;
}