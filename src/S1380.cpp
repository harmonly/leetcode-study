#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> a(m, 1 << 30), b(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i] = min(a[i], matrix[i][j]);
                b[j] = max(b[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == a[i] && matrix[i][j] == b[j])
                    ans.emplace_back(matrix[i][j]);
            }
        }
        return ans;
    }
};