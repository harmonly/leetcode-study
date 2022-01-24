#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            ans += n / 2;
            n = n % 2 == 0 ? n / 2 : n / 2 + 1;
        }
        return ans;
    }

    int numberOfMatches2(int n) { return n - 1; }
};