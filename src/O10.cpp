#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    static constexpr int MOD = 1'000'000'007;

    int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1;
        while (n-- > 0) {
            int c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return a;
    }

    /*int fib2(int n) {
        if (n < 2) return n;
        vector<vector<long>> q{{1, 1}, {1, 0}};
        vector<vector<long>> res = pow(q, n - 1);
        return res[0][0];
    }

    vector<vector<long>> pow(vector<vector<long>>& a, int n) {
        vector<vector<long>> ret{{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) ret = multiply(ret, a);
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>>& a,
                                  vector<vector<long>>& b) {
        vector<vector<long>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j)
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
        }
        return c;
    }*/
};