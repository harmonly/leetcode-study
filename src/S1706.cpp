#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> ans;

   public:
    vector<int> findBall(vector<vector<int>>& grid) {
        for (int j = 0; j < grid[0].size(); ++j) dfs(grid, 0, j);
        return ans;
    }

    vector<int> findBall2(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            int col = j;  // 球的初始位置
            for (auto& row : grid) {
                int dir = row[col];  // 板子的偏移方向 1: 向右偏 2: 向左偏
                col += dir;          // 球往这个方向移动
                if (col < 0 || col == n ||
                    row[col] != dir) {  // 超出左右边界, 形成V型
                    col = -1;
                    break;
                }
            }
            ans[j] = col;
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i == m) {
            ans.push_back(j);
            return;
        }
        int cur = grid[i][j];
        if ((j == 0 && cur == -1) || (j == n - 1 && cur == 1)) {
            ans.push_back(-1);
            return;
        }
        if (cur == 1 && j < n - 1 && grid[i][j + 1] == -1) {
            ans.push_back(-1);
            return;
        }
        if (cur == -1 && j > 0 && grid[i][j - 1] == 1) {
            ans.push_back(-1);
            return;
        }
        dfs(grid, i + 1, j + cur);
    }
};

int main() {
    vector<vector<int>> grid{{1, 1, 1, -1, -1},
                             {1, 1, 1, -1, -1},
                             {-1, -1, -1, 1, 1},
                             {1, 1, 1, 1, -1},
                             {-1, -1, -1, -1, -1}};
    Solution().findBall(grid);
    return 0;
}