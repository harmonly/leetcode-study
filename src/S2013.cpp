#include <bits/stdc++.h>

using namespace std;

class DetectSquares {
   public:
    DetectSquares() {}

    void add(vector<int> point) { g[{point[0], point[1]}]++; }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0], y = point[1];
        for (auto& coor : g) {
            int dx = coor.first.first, dy = coor.first.second;
            int cnt = coor.second;
            if (dx != x && dy != y && abs(x - dx) == abs(y - dy))
                ans += g[{dx, y}] * g[{x, dy}] * cnt;
        }
        return ans;
    }

   private:
    map<pair<int, int>, int> g;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */