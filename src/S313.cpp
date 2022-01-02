#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int m = primes.size();
        vector<int> pointers(m, 1);
        for (int i = 2; i <= n; i++) {
            vector<int> nums(m);
            int _min = INT_MAX;
            for (int j = 0; j < m; j++) {
                nums[j] = dp[pointers[j]] * primes[j];
                _min = min(_min, nums[j]);
            }
            dp[i] = _min;
            for (int j = 0; j < m; j++) {
                if (_min == nums[j]) pointers[j]++;
            }
        }
        return dp[n];
    }
};