#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int k = n - 1;
            int t = -nums[i];
            for (int j = i + 1; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[j] > t) break;
                while (k > j && nums[k] > t - nums[j]) --k;
                if (j == k) break;
                if (nums[j] + nums[k] == t)
                    ans.push_back({-t, nums[j], nums[k]});
            }
        }
        return ans;
    }
};