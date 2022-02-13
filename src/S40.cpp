#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        backtrack(candidates, 0, target);
        return ans;
    }

    void backtrack(vector<int>& nums, int idx, int target) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        } else if (target < 0)
            return;
        for (int i = idx; i < n; ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;  // 去重
            path.emplace_back(nums[i]);
            backtrack(nums, i + 1, target - nums[i]);
            path.pop_back();
        }
    }
};