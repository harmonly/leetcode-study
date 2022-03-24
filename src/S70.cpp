#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            if (i <= 1)
                dp[i] = i + 1;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

class Solution2 {
   public:
    int climbStairs(int n) {
        int f = 0, s = 0, t = 1;
        for (int i = 1; i <= n; ++i) {
            f = s;
            s = t;
            t = f + s;
        }
        return t;
    }
};