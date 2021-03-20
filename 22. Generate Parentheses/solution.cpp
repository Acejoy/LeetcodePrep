#include<bits/stdc++.h>

using namespace std;

void printArray(vector<string> v) {
	for(auto e: v) {
		cout<<e<<endl;
	}
	cout<<"-----------------------"<<endl;
}
void getAns(int n, string s, stack<char> st, vector<string> &v) {
	if(n>=1) {
		int n1=n;
		stack<char> new_st = st;
		n1--;
		new_st.push(')');
		getAns(n1, s+'(',new_st, v );

		if(!st.empty()) {
			st.pop();
			getAns(n, s+')', st, v);
		}
	} else {
		while(!st.empty()) {
			s += ')';
			st.pop();
		}

		v.push_back(s);
	}
}

void getAns2(int n, string s, int m, vector<string> &v) {
	if(n>=1) {
		int n1=n;
		int m1 = m;
		n1--;
		m1++;
		getAns2(n1, s+'(',m1, v );

		if(m>0) {
			//st.pop();
			getAns2(n, s+')', m-1, v);
		}
	} else {
		while(m>0) {
			s += ')';
			m--;
		}

		v.push_back(s);
	}
}

vector<string> generateParenthesis(int n) {
	stack<char> st;
	string s;
	vector<string> v;
	getAns2(n, s, 0, v);

	return v;
}

int main() {

	vector<string> ans;
	int n;
	cin>>n;
	ans = generateParenthesis(n);
	printArray(ans);
	return 0;
}