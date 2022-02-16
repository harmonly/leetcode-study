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