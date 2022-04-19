#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n);
        int d = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) d = 0;
            ans[i] = d++;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) d = 0;
            ans[i] = min(ans[i], d++);
        }
        return ans;
    }
};