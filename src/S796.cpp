#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            string t = s.substr(i) + s.substr(0, i);
            if (t == goal) return true;
        }
        return false;
    }
};