#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            path.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) path.push_back(nums[i]);
            }
            ans.push_back(path);
        }
        return ans;
    }

    void dfs(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(path);
            return;
        }
        path.push_back(nums[idx]);
        dfs(nums, idx + 1);
        path.pop_back();
        dfs(nums, idx + 1);
    }
};