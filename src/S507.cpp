#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int ans = 1;
        // 下面for循环不使用sqrt(num)防止库函数溢出,使用i <= num/i 作为上界判断
        for (int i = 2; i <= num / i; ++i) {
            if (num % i == 0) ans += i + num / i;
        }
        return ans == num;
    }
};