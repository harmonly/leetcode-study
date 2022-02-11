#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) ++ans;
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || !grid[i][j]) return;
        grid[i][j] = 0;
        for (int d = 0; d < 4; ++d) dfs(grid, i + dirs[d][0], j + dirs[d][1]);
    }
};