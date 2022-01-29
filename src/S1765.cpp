#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m));  // 0: 水域, -1: 未访问
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j]) q.push({i, j});
                ans[i][j] = isWater[i][j] ? 0 : -1;
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }

   private:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main() {
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    Solution().highestPeak(isWater);
    return 0;
}