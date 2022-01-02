#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n);
        vector<int> las(n);
        pre[0] = nums[0];
        las[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) pre[i] = max(pre[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; --i) las[i] = min(las[i + 1], nums[i]);
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > pre[i - 1] && nums[i] < las[i + 1])
                ans += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                ans += 1;
        }
        return ans;
    }

    int sumOfBeauties2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int _max = nums[0], _min = nums[n - 1];
        bool states[n - 1];
        memset(states, 0, sizeof(states));
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > _max) {
                states[i] = true;
                _max = nums[i];
            }
        }
        for (int i = n - 2; i >= 1; --i) {
            if (nums[i] < _min)
                _min = nums[i];
            else
                states[i] = false;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (states[i])
                ans += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                ans += 1;
        }
        return ans;
    }
};