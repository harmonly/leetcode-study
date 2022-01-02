#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> lines(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int x : mat[i]) {
                if (x == 0) break;
                cnt += x;
            }
            lines[i] = {cnt, i};
        }

        sort(lines.begin(), lines.end());

        vector<int> ans(k);
        for (int i = 0; i < k; i++) ans[i] = lines[i].second;
        return ans;
    }
};