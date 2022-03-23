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

class Solution2 {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size(), l = 0,
            r = 0;  // 跳 i 步的左右区间 l, r, 最开始的区间为 [0, 0]
        if (n == 1) return 0;
        for (int i = 1;; ++i) {  // 枚举跳跃步数
            int m = 0;           // 最远跳跃距离
            // 枚举跳 i 步能到达的最大距离
            for (int j = l; j <= r; ++j) m = max(m, nums[j] + j);
            // 跳到 n - 1 则返回跳跃步数 i
            if (m >= n - 1) return i;
            l = r + 1;  // 左区间 = 右区间 + 1
            r = m;      // 有区间 = 最远跳跃距离
        }
        return 0;
    }
};