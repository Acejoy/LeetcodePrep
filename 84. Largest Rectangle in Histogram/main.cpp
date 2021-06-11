// help link: https://www.youtube.com/watch?v=vcv3REtIvEo
// we observed that for each value in array, the largest rectabgle area 
// for that index is the rectabgle containing that value.
// Our apprach:
// 1. get the left and right limits(heights >= index's  value) for each index
// 2. now iterate through the indices and calculate max area for each index:
// area = index_val*(rightLimit-leftLimit+1)
// 3. max of all calculated areas

#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v){
    for(auto e: v){
        cout<<e<<' ';
    }

    cout<<'\n';
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> limit;
    vector<int> leftLimit, rightLimit(heights.size(),0);
    int maxArea = INT_MIN, area;

    // leftLimit calculation
    for(int i=0; i<heights.size(); i++){
        if(limit.empty()){
            leftLimit.push_back(0);
        } else {
            
            while(!limit.empty() && heights[limit.top()]>=heights[i]){
                limit.pop();
            }

            if(limit.empty()){
                leftLimit.push_back(0);
            } else{
                leftLimit.push_back(limit.top()+1);
            }
        }
        limit.push(i);
    }

    //clearing the stack
    while(!limit.empty()){
        limit.pop();
    }

    // rightLimit calculation
    for(int i=heights.size()-1; i>=0; i--){
        if(limit.empty()){
            rightLimit[i]=heights.size()-1;
        } else {
            
            while(!limit.empty() && heights[limit.top()]>=heights[i]){
                limit.pop();
            }

            if(limit.empty()){
                rightLimit[i]=heights.size()-1;
            } else{
                rightLimit[i]=limit.top()-1;
            }
        }
        limit.push(i);
    }

    // printVector(leftLimit);
    // printVector(rightLimit);

    for(int i=0; i<heights.size(); i++){
        area = heights[i]*(rightLimit[i]-leftLimit[i]+1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main(){
    vector<int> ques1 = {2,1,5,6,2,3};
    vector<int> ques2 = {2,4};
    cout<<largestRectangleArea(ques1)<<'\n';
    cout<<largestRectangleArea(ques2)<<'\n';
    return 0;
}