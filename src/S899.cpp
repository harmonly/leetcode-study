#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        string ans = s;
        if (k == 1) {
            for (int i = 0; i < n; ++i) {
                s = s.substr(1, n - 1) + s[0];
                if (s < ans) ans = s;
            }
        } else {
            char ch[n];
            for (int i = 0; i < n; ++i) ch[i] = s[i];
            sort(ch, ch + n);
            for (int i = 0; i < n; ++i) ans[i] = ch[i];
        }
        return ans;
    }
};