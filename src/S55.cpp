#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), _max = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= _max) {
                _max = max(_max, i + nums[i]);
                if (_max >= n - 1) return true;
            }
        }
        return false;
    }

    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        int next = 0;
        for (int i = 0; i < n; ++i) {
            next = max(next, i + nums[i]);
            if (next >= n - 1)
                return true;
            else if (next == i)
                return false;
        }
        return false;
    }
};

class Solution2 {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;  // [l, r] 表示跳 i 步的范围
        if (n == 1) return true;
        for (int i = 1; i < n; ++i) {  // i 表示跳跃次数, 范围 [1, n - 1]
            int m = 0;                 // 最远跳的位置
            for (int j = l; j <= r; ++j) m = max(m, nums[j] + j);  // 更新 m
            if (m >= n - 1) return true;  // 如果跳到了最后一位, 则成功
            l = r + 1;                    // 更新左边界
            r = m;                        // 更新右边界
        }
        return false;
    }
};