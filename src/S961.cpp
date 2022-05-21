#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> cnt(10001);
        for (auto& x : nums) {
            cnt[x]++;
            if (cnt[x] > 1) return x;
        }
        return 0;
    }
};