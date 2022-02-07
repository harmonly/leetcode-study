#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {
        unordered_map<int, int> rows, cols, d, ud;
        set<pair<int, int>> pnts;
        for (auto& lamp : lamps) {
            int r = lamp[0], c = lamp[1];
            if (pnts.count(make_pair(r, c))) continue;
            pnts.insert(make_pair(r, c));
            rows[r]++;
            cols[c]++;
            d[r - c]++;
            ud[r + c]++;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int r = query[0], c = query[1];
            if (rows[r] || cols[c] || d[r - c] || ud[r + c])
                ans.push_back(1);
            else
                ans.push_back(0);
            for (int x = r - 1; x <= r + 1; ++x) {
                for (int y = c - 1; y <= c + 1; ++y) {
                    if (x < 0 || y < 0 || x >= n || y >= n) continue;
                    auto p = pnts.find(make_pair(x, y));
                    if (p != pnts.end()) {
                        pnts.erase(p);
                        rows[x]--;
                        cols[y]--;
                        d[x - y]--;
                        ud[x + y]--;
                    }
                }
            }
        }
        return ans;
    }
};