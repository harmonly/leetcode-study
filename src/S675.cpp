#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& forest, int x, int y, int tx, int ty) {
        if (x == tx && y == ty) return 0;
        int m = forest.size(), n = forest[0].size();
        int step = 0;
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        vis[x][y] = 1;
        while (!q.empty()) {
            step++;
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dirs[d][0], nj = j + dirs[d][1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (!vis[ni][nj] && forest[ni][nj] > 0) {
                        if (ni == tx && nj == ty) return step;
                        q.push(make_pair(ni, nj));
                        vis[ni][nj] = 1;
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (forest[i][j] > 1) v.push_back(make_pair(i, j));
        }
        sort(v.begin(), v.end(), [&](const auto a, const auto b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        int x = 0, y = 0;
        int ans = 0;
        for (auto& it : v) {
            int steps = bfs(forest, x, y, it.first, it.second);
            if (steps == -1) return -1;
            x = it.first;
            y = it.second;
            ans += steps;
        }
        return ans;
    }
};