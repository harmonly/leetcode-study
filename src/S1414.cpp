#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findMinFibonacciNumbers(int k) {
        int ans = 0;
        for (int i = 43; i >= 0; --i) {
            int num = fib[i];
            ans += k / num;
            k %= num;
        }
        return ans;
    }

    int findMinFibonacciNumbers2(int k) {
        vector<int> f;
        f.emplace_back(1);
        int a = 1, b = 1;
        while (a + b <= k) {
            int c = a + b;
            f.emplace_back(c);
            a = b;
            b = c;
        }
        int ans = 0;
        for (int i = f.size() - 1; i >= 0 && k > 0; --i) {
            int num = f[i];
            while (k > num) {
                k -= num;
                ans++;
            }
        }
        return ans;
    }

   private:
    const int fib[44] = {1,         1,         2,         3,        5,
                         8,         13,        21,        34,       55,
                         89,        144,       233,       377,      610,
                         987,       1597,      2584,      4181,     6765,
                         10946,     17711,     28657,     46368,    75025,
                         121393,    196418,    317811,    514229,   832040,
                         1346269,   2178309,   3524578,   5702887,  9227465,
                         14930352,  24157817,  39088169,  63245986, 102334155,
                         165580141, 267914296, 433494437, 701408733};
};