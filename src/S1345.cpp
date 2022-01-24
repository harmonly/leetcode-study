#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i) g[arr[i]].push_back(i);
        vector<int> dist(n, INF);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front(), step = dist[u];
            q.pop();
            if (u == n - 1) return dist[u];
            if (u + 1 < n and dist[u + 1] == INF) {
                q.push(u + 1);
                dist[u + 1] = step + 1;
            }
            if (u - 1 >= 0 and dist[u - 1] == INF) {
                q.push(u - 1);
                dist[u - 1] = step + 1;
            }

            for (auto next : g[arr[u]]) {
                if (dist[next] == INF) {
                    q.push(next);
                    dist[next] = dist[u] + 1;
                }
            }
            g.erase(arr[u]);
        }

        return -1;
    }

   private:
    const int INF = 0x3f3f3f3f;
};