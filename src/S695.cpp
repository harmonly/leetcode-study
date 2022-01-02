#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
            return 0;
        grid[x][y] = 0;
        int ans = 1;
        for (int i = 0; i < 4; i++)
            ans += dfs(grid, x + dx[i], y + dy[i]);
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i != grid.size(); i++)
        {
            for (int j = 0; j != grid[0].size(); j++)
            {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};