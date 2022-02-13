#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<char, string> mp{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                   {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                   {'8', "tuv"}, {'9', "wxzy"}};
    vector<string> ans;
    string path;
    int n;

   public:
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        backtrack(digits, 0);
        return ans;
    }

    void backtrack(string digits, int idx) {
        if (path.length() == n && path.length()) {
            ans.emplace_back(path);
            return;
        }
        string str = mp[digits[idx]];
        for (int i = 0; i < str.length(); ++i) {
            path.push_back(str[i]);
            backtrack(digits, idx + 1);
            path.pop_back();
        }
    }
};