#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int a = (x >> i) & 1, b = (y >> i) & 1;
            ans += a ^ b;
        }
        return ans;
    }

    int hammingDistance2(int x, int y) {
        int s = x ^ y, ans = 0;
        while (s) {
            s &= s - 1;
            ++ans;
        }
        return ans;
    }
};