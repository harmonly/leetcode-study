#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> vis;

   public:
    void backtrack(vector<int>& nums, int idx) {
        if (idx == n) {
            ans.emplace_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
                continue;
            path.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, idx + 1);
            vis[i] = 0;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vis.resize(n);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};