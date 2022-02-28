#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> ms;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            if (i >= k - 1) {
                auto it = ms.begin();
                advance(it, k / 2);
                ans.push_back((*it + *prev(it, (1 - k % 2))) / 2);
            }
        }
        return ans;
    }
};