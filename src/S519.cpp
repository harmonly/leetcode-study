#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
        srand(time(nullptr));
    }

    vector<int> flip() {
        int x = rand() % total;
        vector<int> ans;
        total--;
        if (mp.count(x)) {
            ans = {mp[x] / n, mp[x] % n};
        } else {
            ans = {x / n, x % n};
        }
        if (mp.count(total)) {
            mp[x] = mp[total];
        } else {
            mp[x] = total;
        }
        return ans;
    }

    void reset() {
        total = m * n;
        mp.clear();
    }

   private:
    int m, n, total;
    unordered_map<int, int> mp;
};