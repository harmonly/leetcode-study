#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size(), n = s.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (g[i] <= s[j])
                ++ans, ++i, ++j;
            else
                ++j;
        }
        return ans;
    }
};