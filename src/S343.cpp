#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int integerBreak(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(i - j, dp[i - j]) * j);
            }
        }
        return dp[n];
    }

    int integerBreak2(int n) {
        if (n <= 3) return n - 1;
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0)
            return (int)pow(3, quotient);
        else if (remainder == 1)
            return (int)pow(3, quotient - 1) * 4;
        else
            return (int)pow(3, quotient) * 2;
    }
};