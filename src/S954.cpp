#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) cnt[x]++;
        if (cnt[0] & 1) return false;
        vector<int> a;
        for (auto& it : cnt) a.push_back(it.first);
        sort(a.begin(), a.end(), [&](int a, int b) { return abs(a) < abs(b); });
        for (int x : a) {
            if (cnt[2 * x] < cnt[x]) return false;
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};