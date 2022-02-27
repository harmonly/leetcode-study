#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size(), l = 0;
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (int i = 9; i < n; ++i, ++l) {
            string sub = s.substr(l, i - l + 1);
            if (++cnt[sub] == 2) ans.push_back(sub);
        }
        return ans;
    }
};