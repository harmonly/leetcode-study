#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0, n = arr1.size(), m = arr2.size();
        for (int i = 0; i < n; ++i) {
            int ok = 1;
            for (int j = 0; j < m; ++j) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};

class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        for (auto& x : arr1) {
            int p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            int ok = 1;
            if (p < arr2.size()) ok &= (arr2[p] - x > d);
            if (p - 1 >= 0 && p - 1 <= arr2.size()) ok &= (x - arr2[p - 1] > d);
            ans += ok;
        }
        return ans;
    }
};