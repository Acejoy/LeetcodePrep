#include<bits/stdc++.h>

using namespace std;

void printIntervals(vector<vector<int>> &v) {
	for(int i=0; i<v.size(); i++) {
		printf("[%d, %d] ", v[i][0], v[i][1]);
	}

	cout<<"\n-------------------------\n";
} 

bool myComp(const vector<int> &a, const vector<int> &b) {
    return a[0]<b[0];
}

inline bool interleaves(vector<int> &v1, vector<int> &v2) {
    if(v2[0]>=v1[0] && v2[0]<=v1[1]) {
        return true;
    } else {
        return false;
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), myComp);
    //printIntervals(intervals);
    //for(int i=0)
    vector<vector<int>> ans;
    
    for(int i=0; i<intervals.size(); i++) {
    	int n = ans.size();
    	//cout<<i<<' '<<n<<endl;
        if(i==0 || !interleaves(ans[n-1], intervals[i])) {
            ans.push_back(intervals[i]);
        } else {            
            ans[n-1][0] = min(ans[n-1][0], intervals[i][0]);
            ans[n-1][1] = max(ans[n-1][1], intervals[i][1]);
        }           
        
    }
    
    return ans;
}



int main() {
	int n, x, y;
	vector<vector<int>> intervals;

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x>>y;
		intervals.push_back(vector<int> {x,y});
	}

	printIntervals(intervals);

	vector<vector<int>> ans = merge(intervals);

	printIntervals(ans);
	return 0;

}