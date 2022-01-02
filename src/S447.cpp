#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        unordered_map<int, int> map;
        for (auto& p : points) {
            map.clear();
            for (auto& q : points) {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) +
                          (p[1] - q[1]) * (p[1] - q[1]);
                map[dis]++;
            }
            for (auto& mp : map) ans += mp.second * (mp.second - 1);
        }
        return ans;
    }
};