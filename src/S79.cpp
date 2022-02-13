#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    vector<vector<bool>> vis;
    bool ans = false;

   public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != word[0]) continue;
                dfs(board, word, i, j, 0);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, string word, int x, int y, int idx) {
        if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] ||
            board[x][y] != word[idx])
            return;
        if (idx == word.length() - 1) {
            ans = true;
            return;
        }
        vis[x][y] = true;
        for (int d = 0; d < 4; ++d)
            dfs(board, word, x + dirs[d][0], y + dirs[d][1], idx + 1);
        vis[x][y] = false;
    }
};