#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n], ans = 1;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size(), ans = 0;  // ans 表示当前最长上升子序列的长度
        int dp[n];  // dp[i] : 长度为 i 的最长上升子序列的末尾元素的最小值
        for (int i = 0; i < n; ++i) {
            int l = 0, r = ans;  // 范围不大于当前的最长长度 ans
            while (l < r) {      // 寻找 nums[i] 可插入的位置 l
                int mid = l + (r - l) / 2;
                if (dp[mid] < nums[i])
                    l = mid +
                        1;  // 当 nums[i] 大于 dp[mid] 可插入的长度 l = mid + 1
                else
                    r = mid;  // 否则缩小右边界
            }
            dp[l] = nums[i];  // 当长度为 l 时末尾的最小元素为 nums[i], 将
                              // nums[i] 插入 dp[l] 中
            if (l == ans) ++ans;  // 当 l 等于当前最大长度 ans 时, ans++
        }
        return ans;
    }
};