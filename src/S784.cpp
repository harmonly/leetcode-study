#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }

    void backtrack(string s, int index, vector<string> &res) {
        if (s.size() == index) return res.push_back(s);
        if (isdigit(s[index])) return backtrack(s, index + 1, res);
        backtrack(s, index + 1, res);
        s[index] ^= (1 << 5);
        backtrack(s, index + 1, res);
    }
};