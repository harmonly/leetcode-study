#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        int dp[n - 1], dp2[n];
        dp[0] = nums[0], dp2[1] = nums[1];
        dp[1] = max(dp[0], nums[1]), dp2[2] = max(dp2[1], nums[2]);
        for (int i = 2; i < n - 1; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        for (int i = 3; i < n; ++i)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        return max(dp[n - 2], dp2[n - 1]);
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    cout << Solution().rob(nums) << endl;
    return 0;
}