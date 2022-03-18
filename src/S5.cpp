#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        int begin = 0, maxLen = 0;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

class Solution2 {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            if (i + 1 < n) dp[i][i + 1] = s[i] == s[i + 1];
        }
        for (int i = 2; i < n; ++i) {
            for (int l = 0; l + i < n; ++l) {
                int r = l + i;
                if (s[l] == s[r] && dp[l + 1][r - 1]) dp[l][r] = 1;
            }
        }
        int idx = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (dp[i][j] && j - i + 1 > len) {
                    idx = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(idx, len);
    }
};