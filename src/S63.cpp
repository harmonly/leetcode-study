#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = !obstacleGrid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] * !obstacleGrid[i][0];
        for (int i = 1; i < n; ++i)
            dp[0][i] = dp[0][i - 1] * !obstacleGrid[0][i];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] * !obstacleGrid[i - 1][j] +
                           dp[i][j - 1] * !obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[m - 1][n - 1] ? 0 : dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0}, {0, 1}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}