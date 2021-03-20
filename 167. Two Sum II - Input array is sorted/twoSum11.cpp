/* the question link is: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
the pseudocode is:
    take 2 indices ,initialy one(i) points to start of array and other(j) at the end.
    Enter a loop while i<j, if arr[i] +arr[j] == target , exit; else if >target , decrease j, else increase i.

*/

#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int> v = {2,7,11,15};
    int i = 0, j = v.size() -1 ;
    int target = 9;
    int sum;

    bool flag = false;

    while(i<j) {
        
        sum = v[i] +v[j] ;

        if  ( sum == target) {
            flag = true;
            break;
        } else if ( sum > target ) {
            j--;
        } else {
            i++;
        }
    }

    if ( flag) {
        cout<<i<<' '<<j<<endl;
    } else {
        cout<<-1<<' '<<-1<<endl;
    }
    

    return 0;
}