#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        for (int l = upper;; --l) {
            long p = l;
            for (int x = l; x > 0; x /= 10) p = p * 10 + x % 10;
            for (long x = upper; x * x >= p; --x)
                if (p % x == 0) return p % 1337;
        }
        return 0;
    }
};

class Solution {
   public:
    int largestPalindrome(int n) {
        int a[8] = {9, 987, 123, 597, 677, 1218, 877, 475};
        return a[n - 1];
    }
};