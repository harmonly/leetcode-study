#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n], ans = 1;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};