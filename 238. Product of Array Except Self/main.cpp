/*
We can do it in O(1) time using division operator but cant use it(ATQ).
This approach:
we use 2 products , leftside(0 to index-1) of current index, rightside(inde+1 to last) of current index.

we can store the rightside product in the answer vector and calculate leftside product 
while traversing the number vector, and filling the final values in answer vector.
*/
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    for (auto e : v) {
        cout << e << ' ';
    }
    cout << '\n';
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);

    int rightSide = 1;

    // filling the ans vector with righSide product
    for (int i = nums.size() - 2; i >= 0; i--) {
        ans[i] = ans[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++) {
        ans[i] *= rightSide;
        rightSide *= nums[i];
    }

    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(v);
    printVector(ans);
    return 0;
}