#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dirs[4][2] = {{1,  0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& a, int i, int j) {
        a[i][j] = 1;
        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d][0], y = j + dirs[d][1];
            if (x < 0 || x >= m || y < 0 || y >= n || a[x][y]) continue;
            if (heights[i][j] <= heights[x][y]) dfs(heights, a, x, y);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> a(m, vector<int>(n));
        vector<vector<int>> b(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            dfs(heights, a, i, 0);
            dfs(heights, b, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(heights, a, 0, i);
            dfs(heights, b, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (a[i][j] && b[i][j])
                    ans.push_back(vector<int>{i, j});
        }
        return ans;
    }
};