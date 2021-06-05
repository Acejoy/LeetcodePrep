/*
here we are supposed to find max area between two rods of certain length(given
by corresponding vector values).Area(rectangle) = length*breadth.
We reduce search operations by setting initial breadth to max. Now breadth can only increase.
So to increase area only height can be increased, so we move the ptr with smaller length and
recalculate area and compare with maxArea.
*/
#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    
    int maxArea = INT_MIN;
    
    int leftPtr = 0;
    int rightPtr = height.size()-1;
    
    int recWidth = 0;
    int recHeight =0;
    
    while(leftPtr<rightPtr) {
        recWidth = rightPtr-leftPtr;
        recHeight = min(height[leftPtr],height[rightPtr]);
        
        maxArea = max(maxArea, recHeight*recWidth);
        
        if(height[leftPtr]<height[rightPtr]) {
            leftPtr++;
        } else {
            rightPtr--;
        }
        
    }
    
    return maxArea;
}

int main(){
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(v)<<'\n';
    return 0;
}