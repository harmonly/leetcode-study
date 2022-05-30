#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dis[m][n];
        memset(dis, 0x3f, sizeof(dis));
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        deque<pair<int, int>> q;
        q.emplace_back(0, 0);
        dis[0][0] = 0;
        while (!q.empty()) {
            auto x = q.front().first, y = q.front().second;
            q.pop_front();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                int new_dis = dis[x][y] + (grid[x][y] != d + 1);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                    new_dis > dis[nx][ny])
                    continue;
                dis[nx][ny] = new_dis;
                if (grid[x][y] != d + 1)
                    q.emplace_back(nx, ny);
                else
                    q.emplace_front(nx, ny);
            }
        }
        return dis[m - 1][n - 1];
    }
};