#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0], second = INT_MAX;
        int n = nums.size();
        for (auto& num : nums) {
            if (num > second)
                return true;
            else if (num > first)
                second = num;
            else
                first = num;
        }
        return false;
    }
};