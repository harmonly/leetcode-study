#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> ans;

   public:
    vector<string> generateParenthesis(int n) {
        backtrack("", n, n);
        return ans;
    }

    void backtrack(string str, int l, int r) {
        if (l == 0 && r == 0) {
            ans.emplace_back(str);
            return;
        }
        if (l > 0) backtrack(str + '(', l - 1, r);
        if (r > l) backtrack(str + ')', l, r - 1);
    }
};