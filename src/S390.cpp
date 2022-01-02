#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lastRemaining(int n) {
        int a1 = 1, an = n;
        int k = 0, cnt = n, step = 1;
        while (cnt != 1) {
            if (k % 2 == 0) {
                a1 += step;
                an = (cnt % 2) ? an : an - step;
            } else {
                an -= step;
                a1 = (cnt % 2) ? a1 + step : a1;
            }
            step <<= 1;
            cnt >>= 1;
            k++;
        }
        return a1;
    }

    // 详细推导 https://blog.csdn.net/afei__/article/details/83689502
    int lastRemaining2(int n) {
        return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining2(n / 2));
    }
};

int main() {
    int n = 6;
    cout << Solution().lastRemaining(n) << endl;
    return 0;
}