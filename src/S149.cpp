#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        if (n < 3) return n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    int ddx = points[j][0] - points[k][0];
                    int ddy = points[j][1] - points[k][1];
                    if (dx * ddy == ddx * dy) ++cnt;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }

    int maxPoints2(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int k = gcd(dx, dy);
                string key = to_string(dx / k) + to_string(dy / k);
                cnt = max(cnt, ++mp[key]);
            }
            ans = max(ans, cnt + 1);
            mp.clear();
        }
        return ans;
    }

    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
};