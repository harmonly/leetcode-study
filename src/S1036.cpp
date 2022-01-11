#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

   public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                          vector<int>& target) {
        for (auto& p : blocked) set.insert(p[0] * BASE + p[1]);
        int n = blocked.size();
        MAX = n * (n - 1) / 2;
        return check(source, target) && check(target, source);
    }

   private:
    int EDGE = 1e6, MAX = 1e5;
    LL BASE = 131;
    unordered_set<LL> set;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool check(vector<int>& a, vector<int>& b) {
        unordered_set<LL> vis;
        queue<pair<int, int>> que;
        que.push({a[0], a[1]});
        vis.insert(a[0] * BASE + a[1]);
        while (que.size() && vis.size() <= MAX) {
            auto t = que.front();
            que.pop();
            int x = t.first, y = t.second;
            if (x == b[0] && y == b[1]) return true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx < 0 || nx >= EDGE || ny < 0 || ny >= EDGE) continue;
                if (set.count(nx * BASE + ny)) continue;
                if (vis.count(nx * BASE + ny)) continue;
                que.push({nx, ny});
                vis.insert(nx * BASE + ny);
            }
        }
        return vis.size() > MAX;
    }
};