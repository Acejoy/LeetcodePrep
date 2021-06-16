#include<bits/stdc++.h>

using namespace std;

void printParens(vector<string> &v){
    for(auto e: v){
        cout<<e<<' ';
    }

    cout<<'\n';
}

void generateFn(int leftParens, vector<string> &ans, string prefix, int rightParens, int N){
    if(prefix.size()==2*N){
        ans.push_back(prefix);
    } else {
        if(rightParens<leftParens){
            generateFn(leftParens, ans, prefix+')',rightParens+1, N);
        }

        if(leftParens<N){
            generateFn(leftParens+1, ans, prefix+'(', rightParens, N);
        }
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateFn(0, res, "", 0, n);
    return res;
}

int main(){

    int num;
    cout<<"Enter number of parens:";
    cin>>num;
    vector<string> res = generateParenthesis(num);
    printParens(res);

    cout<<res.size()<<'\n';
    return 0;
}