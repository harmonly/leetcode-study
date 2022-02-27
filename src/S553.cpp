#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string ans = "";
        ans += to_string(nums[0]);
        if (n != 1) {
            ans += "/";
            if (n != 2) ans += "(";
        }
        for (int i = 1; i < n; ++i) ans += to_string(nums[i]) + "/";
        if (n != 1) {
            ans.pop_back();
            if (n != 2) ans += ")";
        }
        return ans;
    }
};