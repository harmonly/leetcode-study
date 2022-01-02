#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];  //三角形的左侧边界
            for (int j = 1; j < i; ++j)
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];  //三角形的右侧边界
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }

    int minimumTotal2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            int curr = i & 1;
            int prev = 1 - curr;
            f[curr][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; j++)
                f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
            f[curr][i] = f[prev][i - 1] + triangle[i][i];
        }
        return *min_element(f[(n - 1) & 1].begin(), f[(n - 1) & 1].end());
    }

    //自底向上
    int minimumTotal3(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};