#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto& num : nums) ++mp[num];
        for (auto& it : mp)
            if (it.second == 1) ans += it.first;
        return ans;
    }
};