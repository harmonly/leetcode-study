#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countPrimes(int n) {
        vector<int> isprime(n + 1, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isprime[i]) {
                ++ans;
                for (int j = 2; i * j < n; ++j) isprime[i * j] = 0;
            }
        }
        return ans;
    }
};