/*
This question is very similiar to 198. House Robber
In this question the 1st and last homes are neighbors as in a circular ring.
So we calculate 2 max, one for [0, last-1], and [1, last element].
DOing this, we eliminate the case where first and last houses both may be
robbed.


There are two cases without the first element and without the last element.

Actually there are four cases, but with first and last element is invalid, and
without both is already covered by either case described above. which is R R, R
N, N R and N N, where R stands for rob and N stands for no rob. R R is invalid.
R N and N N is covered by without last element, and NR and N N is covered by
without first element.
*/
#include <bits/stdc++.h>

using namespace std;

int robHelper(vector<int>& nums, int lowerLimit, int upperLimit,
              vector<int>& dpTable) {
    dpTable[lowerLimit] = nums[lowerLimit];
    dpTable[lowerLimit + 1] = max(nums[lowerLimit], nums[lowerLimit + 1]);

    for (int i = lowerLimit + 2; i <= upperLimit; i++) {
        dpTable[i] = max(nums[i] + dpTable[i - 2], dpTable[i - 1]);
    }

    return dpTable[upperLimit];
}

int rob(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    if (nums.size() == 1) {
        return nums[0];
    } else if (nums.size() == 2) {
        return max(nums[0], nums[1]);
    } else {
        int max1 = robHelper(nums, 0, nums.size() - 2, ans);
        int max2 = robHelper(nums, 1, nums.size() - 1, ans);

        return max(max1, max2);
    }
}

int main() {
    vector<int> ques = {2, 3, 2};
    cout << rob(ques) << '\n';
    return 0;
}