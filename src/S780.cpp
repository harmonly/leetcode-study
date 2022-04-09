#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0) {
            if (sx == tx && sy == ty) return true;
            if (tx > ty)
                tx -= max((tx - sx) / ty, 1) * ty;
            else
                ty -= max((ty - sy) / tx, 1) * tx;
        }
        return false;
    }
};

class Solution2 {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy) {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }
        if (tx < sx || ty < sy) return false;
        return tx == sx ? (ty - sy) % tx == 0 : (tx - sx) % ty == 0;
    }
};