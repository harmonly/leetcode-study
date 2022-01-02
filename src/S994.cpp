#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n));
        queue<pair<int, int>> q;
        int ans = 0, fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.emplace(i, j);
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty()) {
            auto var = q.front();
            int i = var.first, j = var.second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    grid[ni][nj] == 1) {
                    time[ni][nj] = time[i][j] + 1;
                    grid[ni][nj] = 2;
                    q.emplace(ni, nj);
                    ans = time[ni][nj];
                    fresh--;
                }
            }
        }
        return fresh ? -1 : ans;
    }
};

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << Solution().orangesRotting(grid) << endl;
    return 0;
}