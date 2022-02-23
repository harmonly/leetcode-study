#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int sum = 0;
            for (int x = i; x > 0; x /= 10) {
                sum ^= x % 10 & 1;  // 用异或代替加法
            }
            ans += sum ^ 1;  // 偶数就 +1
        }
        return ans;
    }
};