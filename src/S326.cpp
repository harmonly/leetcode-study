#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isPowerOfThree(int n) {
        long long x = 1;
        while (x < n) x *= 3;
        return x == n;
    }
    bool isPowerOfThree2(int n) {
        while (n && n % 3 == 0) n /= 3;
        return n == 1;
    }
};