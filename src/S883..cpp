#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = 0; j < n; j++) {
                a += grid[i][j] > 0 ? 1 : 0;
                x = max(x, grid[j][i]);
                y = max(y, grid[i][j]);
            }
            b += x;
            c += y;
        }
        return a + b + c;
    }
};