#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        int ans = 0;     // 跳跃次数
        int maxPos = 0;  // 目前能跳到的最远位置
        int end = 0;  // 上次跳跃可达范围右边界（下次的最右起跳点）
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {  // 到达上次跳跃能到达的右边界了
                end = maxPos;  // 目前能跳到的最远位置变成了下次起跳位置的右边界
                ans++;  // 进入下一次跳跃
            }
        }
        return ans;
    }

    int jump2(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 0;
        for (int i = 1, j = 0; i < n; ++i) {
            while (j + nums[j] < i) ++j;
            dp[i] = dp[j] + 1;
        }
        return dp[n - 1];
    }
};