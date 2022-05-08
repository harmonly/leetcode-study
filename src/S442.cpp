#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_set<int> st;
        for (auto& x : nums) {
            if (st.count(x)) {
                ans.push_back(x);
                continue;
            }
            st.insert(x);
        }
        return ans;
    }
};