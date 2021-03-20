#include<bits/stdc++.h>

using namespace std;

bool compare(pair<vector<int>, float> &p1, pair<vector<int>, float> &p2) {
	return p1.second> p2.second;
}

void printPoints(vector<vector<int>> &v) {
	for(auto e: v) {
		cout<<e[0]<<" "<<e[1]<<endl;
	}
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

	float distance2Origin;
	vector<pair<vector<int>, float>> pointDistances;
	vector<vector<int>> ans;

	for(int i=0; i<points.size(); i++) {
		distance2Origin = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
		pointDistances.push_back({points[i], distance2Origin}); 
	}

	make_heap(pointDistances.begin(), pointDistances.end(), compare);

	/*for(auto e: pointDistances) {
		cout<<e.first[0]<<" "<<e.first[1]<<" "<<e.second<<endl;
	}*/

	for(int i=0; i<K; i++) {
		
		pair<vector<int>, float> p;
		p = pointDistances.front();		
		pop_heap(pointDistances.begin(), pointDistances.end(), compare);
		pointDistances.pop_back();
		vector<int> v = {p.first[0], p.first[1]};
		ans.push_back(v);

	}

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	int n, x, y, k;
	//cout<<"Enter the number of points:";
	cin>>n;

	vector<vector<int>> setOfPoints;
	//cout<<"Enter the points(x,y):"<<endl;

	for(int i=0;i<n; i++) {
		cin>>x;
		cin>>y;
		vector<int> v={x, y};
		setOfPoints.push_back(v);
	}

	cin>>k;

	//printPoints(setOfPoints);
	vector<vector<int>> result = kClosest(setOfPoints,k);
	printPoints(result);
	return 0;
}