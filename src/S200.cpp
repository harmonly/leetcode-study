#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    grid[i][j] = '2';
                    continue;
                } else if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '0') return;
        grid[x][y] = '2';
        int m = grid.size(), n = grid[0].size();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] == '1') dfs(grid, nx, ny);
        }
    }
};

int main() {
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << Solution().numIslands(grid) << endl;
    return 0;
}