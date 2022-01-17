#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countVowelPermutation(int n) {
        long ans = 0;
        long dp[n + 1][5];
        for (int i = 0; i < 5; ++i) dp[1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][2];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
            dp[i][2] = dp[i - 1][1] + dp[i - 1][3];
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = dp[i - 1][3] + dp[i - 1][2];
            for (int j = 0; j < 5; ++j) dp[i][j] %= MOD;
        }
        for (int i = 0; i < 5; ++i) ans += dp[n][i];
        return ans % MOD;
    }

   private:
    const int MOD = 1e9 + 7;
};