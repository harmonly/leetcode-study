#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int val = matrix[r - 1][c];
                if (c - 1 >= 0) val = min(val, matrix[r - 1][c - 1]);
                if (c + 1 < n) val = min(val, matrix[r - 1][c + 1]);
                matrix[r][c] += val;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }

    int minFallingPathSum2(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) ans = min(ans, find(matrix, i));
        return ans;
    }

    int find(vector<vector<int>>& mat, int index) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) dp[0][i] = i == index ? mat[0][i] : INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                int val = mat[i][j];
                if (dp[i - 1][j] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + val);
                if (j - 1 >= 0 && dp[i - 1][j - 1] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + val);
                if (j + 1 < n && dp[i - 1][j + 1] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + val);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};