#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int a = 0; a < n; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < n; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int c = b + 1, d = n - 1;
                while (c < d) {
                    LL sum = nums[a] + nums[b];
                    sum += nums[c] + nums[d];
                    if (sum > target)
                        --d;
                    else if (sum < target)
                        ++c;
                    else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c] == nums[++c])
                            ;
                        while (c < d && nums[d] == nums[--d])
                            ;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    Solution().fourSum(nums, 0);
}