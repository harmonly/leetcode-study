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