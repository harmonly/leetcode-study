#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string truncateSentence(string s, int k) {
        int i = 0;
        for (; i < s.size(); i++) {
            if (s[i] == ' ') k--;
            if (k == 0) break;
        }
        return s.substr(0, i);
    }
};