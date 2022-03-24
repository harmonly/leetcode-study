#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int m, n;

    int calc(vector<vector<int>>& img, int x, int y) {
        int sum = 0, cnt = 0;
        for (int i = max(0, x - 1); i <= min(m - 1, x + 1); ++i) {
            for (int j = max(0, y - 1); j <= min(n - 1, y + 1); ++j) {
                sum += img[i][j];
                ++cnt;
            }
        }
        return sum / cnt;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        m = img.size();
        n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = calc(img, i, j);
            }
        }
        return ans;
    }
};