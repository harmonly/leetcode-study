#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min((int)s.length(), numRows));
        int cur = 0, down = 0;
        for (auto& c : s) {
            rows[cur] += c;
            if (cur == 0 || cur == numRows - 1) down = !down;
            cur += down ? 1 : -1;
        }
        string ans;
        for (auto& row : rows) ans += row;
        return ans;
    }
};