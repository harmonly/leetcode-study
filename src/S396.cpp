#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f = 0;
        for (int i = 0; i < n; ++i) f += i * nums[i];
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f += sum - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};