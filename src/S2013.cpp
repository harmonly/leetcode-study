#include <bits/stdc++.h>

using namespace std;

class DetectSquares {
   private:
    map<pair<int, int>, int> mp;

   public:
    DetectSquares() {}

    void add(vector<int> point) { mp[{point[0], point[1]}]++; }

    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        for (const auto& [pnt, cnt] : mp) {
            auto& [a, b] = pnt;
            // 防止横纵坐标相同
            if (a == x || b == y) continue;
            // 正方形判断
            if (abs(a - x) == abs(b - y)) res += mp[{a, y}] * mp[{x, b}] * cnt;
        }
        return res;
    }
};