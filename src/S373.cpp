#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        bool flag = true;
        if (n > m) {
            swap(nums1, nums2);
            swap(n, m);
            flag = false;
        }
        auto cmp = [&](const auto& a, const auto& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
            cmp);
        for (int i = 0; i < min(n, k); ++i) q.push({i, 0});
        while (ans.size() < k && q.size()) {
            int a = q.top().first, b = q.top().second;
            q.pop();
            flag ? ans.push_back({nums1[a], nums2[b]})
                 : ans.push_back({nums2[b], nums1[a]});
            if (b + 1 < m) q.push({a, b + 1});
        }
        return ans;
    }
};