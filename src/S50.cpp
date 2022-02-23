#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        long long N = n;
        return n > 0 ? quickMul(x, n) : 1.0 / quickMul(x, -N);
    }

    double quickMul(double x, long long N) {
        if (N == 0) return 1.0;
        double y = quickMul(x, N / 2);
        return N & 1 ? x * y * y : y * y;
    }

    double quickMul2(double x, long long N) {
        double ans = 1.0;
        // contribution 的初始值为 x
        double cont = x;
        while (N > 0) {
            // 如果二进制的最低位为 1, 那么需要计入贡献
            if (N & 1) ans *= cont;
            // 将贡献不断地平方
            cont *= cont;
            // 舍弃 N 二进制的最低位, 这样每次只需要判断最低位即可
            N >>= 1;
        }
        return ans;
    }
};

int main() {
    cout << Solution().myPow(2, -2) << endl;
    return 0;
}