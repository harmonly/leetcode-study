#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        int dp[n], cnt[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1, cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j]) continue;
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i])
                    cnt[i] += cnt[j];
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i];
            } else if (dp[i] == maxLen)
                ans += cnt[i];
        }
        return ans;
    }
};