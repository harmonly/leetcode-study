#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = -1;
        while (n) {
            int cur = n % 2;
            if (cur == pre) return false;
            pre = cur;
            n >>= 1;
        }
        return true;
    }
};

class Solution2 {
public:
    bool hasAlternatingBits(int n) {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};