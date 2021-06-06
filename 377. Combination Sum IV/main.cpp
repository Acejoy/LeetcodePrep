#include <bits/stdc++.h>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<uint32_t> dpTable(target + 1, 0);

    dpTable[0]=1;
    for (int i = 1; i <= target; i++) {
        for (auto number : nums) {
            if (number <= i) {
                dpTable[i] += dpTable[i - number];
            }
        }
    }

    return dpTable[target];
}

int main() {
    vector<int> v = {1, 2, 3};
    int target = 4;
    cout << combinationSum4(v, target) << '\n';
    return 0;
}