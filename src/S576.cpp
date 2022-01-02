#include <bits/stdc++.h>

using namespace std;

class Solution {
   private:
    static constexpr int MOD = 1'000'000'007;

   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int outCounts = 0;
        int dp[maxMove + 1][m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][startRow][startColumn] = 1;
        for (int move = 0; move < maxMove; ++move) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    int count = dp[move][x][y];
                    if (count > 0) {
                        for (int i = 0; i < 4; ++i) {
                            int dx = x + directions[i][0],
                                dy = y + directions[i][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n)
                                dp[move + 1][dx][dy] =
                                    (dp[move + 1][dx][dy] + count) % MOD;
                            else
                                outCounts = (outCounts + count) % MOD;
                        }
                    }
                }
            }
        }
        return outCounts;
    }
};