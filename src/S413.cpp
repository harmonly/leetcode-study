#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 0;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

    int numberOfArithmeticSlices2(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int dp = 0, sum = 0;
        for (int i = 2; i < n; i++) {
            nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? sum += ++dp
                                                               : dp = 0;
        }
        return sum;
    }
};