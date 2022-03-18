#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            int l = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '(')
                    ++l;
                else {
                    if (!l)
                        break;
                    else
                        --l;
                }
                if (!l) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    int longestValidParentheses(string s) {
        int n = s.length(), ans = 0;
        if (n == 0) return ans;
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
                else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                    dp[i] = dp[i - 1] +
                            ((i - dp[i - 1]) > 1 ? dp[i - dp[i - 1] - 2] : 0) +
                            2;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};