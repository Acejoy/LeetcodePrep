#include<bits/stdc++.h>

using namespace std;

string reverseStr(string s, int k) {
    
    int curIdx = 0;
    int strSize = s.size();
    int leftLimit;
    int rightLimit;
    int num_of_2k_chunks = strSize/(2*k);
    int remainderChars = strSize%(2*k);
    char temp;
    
    for(int i=0; i<num_of_2k_chunks; i++) {
        leftLimit = curIdx;
        rightLimit = curIdx+k-1;
        
        while(leftLimit < rightLimit) {
            temp = s[leftLimit];
            s[leftLimit] = s[rightLimit];
            s[rightLimit] = temp;
            
            leftLimit++;
            rightLimit--;
        }
        
        curIdx += 2*k;
    }
    
    if(remainderChars>0) {
        leftLimit = curIdx;
        rightLimit = min(strSize-1, curIdx+k-1);
        
        while(leftLimit < rightLimit) {
            temp = s[leftLimit];
            s[leftLimit] = s[rightLimit];
            s[rightLimit] = temp;
            
            leftLimit++;
            rightLimit--;
        }
    }
    
    
    
    return s;
}

int main() {
	int k;
	string s;
	cout<<"enter string?:";
	cin>>s;
	cout<<"enter the K:";
	cin>>k;
	cout<<reverseStr(s, k);
	return 0;
}