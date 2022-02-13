#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            path.emplace_back(nums[i]);
            backtrack(nums, i, target - nums[i]);  // 回溯时可以多次选择同一个数,
                                                   // 此处 idx 传入 i 而非 i + 1
            path.pop_back();
        }
    }
};