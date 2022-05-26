#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> ans;
        map<pair<int, int>, int> mp;
        int tallest = 0;
        for (int i = 0; i < n; ++i) {
            int l = positions[i][0], h = positions[i][1], r = l + h;
            int tall = 0;
            for (auto& p : mp) {
                int pl = p.first.first, pr = p.first.second;
                int ph = p.second;
                if (r <= pl || l >= pr) continue;
                tall = max(tall, ph);
            }
            mp[{l, r}] = h + tall;
            tallest = max(tallest, tall + h);
            ans.push_back(tallest);
        }
        return ans;
    }
};