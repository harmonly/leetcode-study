#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                int j = i + 1;
                int diff = 1;
                while (j < n) {
                    diff += (s[j] == '(' ? 1 : -1);
                    if (diff == 0) break;
                    ans += s[j];
                    ++j;
                }
                i = j - 1;
            }
        }
        return ans;
    }
};