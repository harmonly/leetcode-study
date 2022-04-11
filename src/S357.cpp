#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - i + 1);
        }
        return dp[n];
    }
};

class Solution2 {
   public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1, cur = 9;
        for (int i = 1; i <= n; ++i) {
            ans += cur;
            cur *= 10 - i;
        }
        return ans;
    }
};