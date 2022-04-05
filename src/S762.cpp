#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i)
            ans += isprime(__builtin_popcount(i));
        return ans;
    }

    bool isprime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }
};