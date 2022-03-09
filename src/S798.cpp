#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (i - nums[i] + n + 1) % n;
            d[l]++, d[r]--;
            if (l >= r) d[0]++;
        }
        int ans = 0, score = 0, maxScore = 0;
        for (int k = 0; k < n; ++k) {
            score += d[k];
            if (score > maxScore) {
                ans = k;
                maxScore = score;
            }
        }
        return ans;
    }
};