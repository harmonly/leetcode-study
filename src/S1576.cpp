#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string modifyString(string s) {
        int n = s.size();
        s = ' ' + s + ' ';
        for (int i = 1; i <= n; ++i) {
            if (s[i] != '?') continue;
            int j = i + 1;
            while (j <= n && s[j] == '?') ++j;
            for (int k = i; k <= n && k < j; ++k) {
                for (int t = 0; t < 26; ++t) {
                    char ch = 'a' + t;
                    if (ch != s[i] && ch != s[j] && ch != s[k - 1]) {
                        s[k] = ch;
                        break;
                    }
                }
            }
            i = j;
        }
        return s.substr(1, n);
    }

    string modifyString2(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 3 && s[i] == '?'; ++c) {
                bool flag = true;
                if (i - 1 >= 0 && s[i - 1] == 'a' + c) flag = false;
                if (i + 1 < n && s[i + 1] == 'a' + c) flag = false;
                if (flag) s[i] = 'a' + c;
            }
        }
        return s;
    }
};