#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                            {1, -2},  {1, 2},  {2, -1},  {2, 1}};

   public:
    double knightProbability(int n, int k, int row, int column) {
        double dp[n][n][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int p = 0; p <= k; ++p) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (p == 0)
                        dp[i][j][p] = 1;
                    else {
                        for (int d = 0; d < 8; ++d) {
                            int nx = i + dirs[d][0], ny = j + dirs[d][1];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                                continue;
                            dp[i][j][p] += dp[nx][ny][p - 1] / 8;
                        }
                    }
                }
            }
        }
        return dp[row][column][k];
    }
};