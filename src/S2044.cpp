#include <bits/stdc++.h>

using namespace std;

class Solution {
    int mx = 0, n;

   public:
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        for (auto& num : nums) mx |= num;
        return dfs(nums, 0, 0);
    }

    int dfs(vector<int>& nums, int idx, int cur) {
        if (idx == n) return cur == mx ? 1 : 0;
        return dfs(nums, idx + 1, cur) + dfs(nums, idx + 1, cur | nums[idx]);
    }
};