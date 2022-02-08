#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0, n = isConnected.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(isConnected, vis, i);
                ++ans;
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& conn, vector<bool>& vis, int i) {
        for (int j = 0; j < conn.size(); ++j) {
            if (conn[i][j] && !vis[j]) {
                vis[j] = true;
                dfs(conn, vis, j);
            }
        }
    }
};