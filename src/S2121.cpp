#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        unordered_map<int, long long> sum;
        vector<long long> ans(n);
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            if (cnt.count(val)) ans[i] += 1ll * i * cnt[val] - sum[val];
            cnt[val]++;
            sum[val] += i;
        }
        cnt.clear();
        sum.clear();
        for (int i = n - 1; i >= 0; --i) {
            int val = arr[i];
            if (cnt.count(val)) ans[i] += sum[val] - 1ll * i * cnt[val];
            cnt[val]++;
            sum[val] += i;
        }
        return ans;
    }
};