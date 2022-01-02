#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(grid);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    val = min(val, dp[i - 1][k]);
                }
                dp[i][j] += val;
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    int minFallingPathSum2(vector<vector<int>>& grid) {
        int n = grid.size();
        int first_sum = 0, first_pos = -1, second_sum = 0;
        for (int i = 0; i < n; ++i) {
            int fs = INT_MAX, fp = -1, ss = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int cur_sum =
                    (first_pos != j ? first_sum : second_sum) + grid[i][j];
                if (cur_sum < fs) {
                    ss = fs;
                    fs = cur_sum;
                    fp = j;
                } else if (cur_sum < ss)
                    ss = cur_sum;
            }
            first_sum = fs;
            first_pos = fp;
            second_sum = ss;
        }

        return first_sum;
    }
};