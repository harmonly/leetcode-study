#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < n; ++i) dp[0][i] = 1;
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }

    int uniquePaths2(int m, int n) {
        long long ans = 1;
        // 从左上角到右下角的过程中，我们需要移动 m+n−2 次，其中有 m-1
        // 次向下移动，n-1 次向右移动。因此路径的总数，就等于从 m+n-2
        // 次移动中选择 m-1 次向下移动的方案数
        for (int x = n, y = 1; y < m; ++x, ++y) ans = ans * x / y;
        return ans;
    }
};