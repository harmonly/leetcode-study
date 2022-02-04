#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) dfs(grid, i, j, 0);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int gold) {
        gold += grid[x][y];
        ans = max(ans, gold);
        
        int rec = grid[x][y];
        grid[x][y] = 0;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny])
                dfs(grid, nx, ny, gold);
        }

        grid[x][y] = rec;
    }

   private:
    int m, n, ans = 0;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main() {
    vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << Solution().getMaximumGold(grid) << endl;
    return 0;
}