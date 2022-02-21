#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            i++;
        }
        return right << i;
    }

    int rangeBitwiseAnd2(int left, int right) {
        while (right > left) right &= right - 1;
        return right;
    }
};