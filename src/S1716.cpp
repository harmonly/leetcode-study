#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int totalMoney(int n) {
        int ans = 0;
        int k = n % 7;
        int a1 = n / 7 + 1;
        int an = a1 + k - 1;
        for (int i = 1; i <= n / 7; i++) ans += 7 * (i + 3);
        ans += k * (a1 + an) / 2;
        return ans;
    }

    int totalMoney2(int n) {
        int a = n / 7;
        int b = n % 7;
        return (a * (7 * a + 49) + b * (b + 1)) / 2 + b * a;
    }
};