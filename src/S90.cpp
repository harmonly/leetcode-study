#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            path.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask >> (i - 1) & 1) == 0 &&
                        nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    path.push_back(nums[i]);
                }
            }
            if (flag) ans.push_back(path);
        }
        return ans;
    }
};