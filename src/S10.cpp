#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dp[21][31];

   public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j]) {
                    if (p[j] == '.') dp[i + 1][j + 1] = 1;
                    if (isalpha(p[j]) && s[i] == p[j]) dp[i + 1][j + 1] = 1;
                    if (j < n - 1 && p[j + 1] == '*') dp[i][j + 2] = 1;
                    if (p[j] == '*') {
                        dp[i][j + 1] = 1;
                        if (isalpha(p[j - 1]) && s[i] == p[j - 1])
                            dp[i + 1][j] = 1;
                        if (p[j - 1] == '.') dp[i + 1][j] = 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};