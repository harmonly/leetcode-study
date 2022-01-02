#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2
                                        : max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};