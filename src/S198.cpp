#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int dp[n];
        dp[0] = nums[0], dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }

    int rob2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int pre = nums[0], ans = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int tmp = ans;
            ans = max(ans, pre + nums[i]);
            pre = tmp;
        }
        return ans;
    }
};