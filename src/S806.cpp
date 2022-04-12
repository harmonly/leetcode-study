#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, width = 0;
        for (auto& ch : s) {
            width += widths[ch - 'a'];
            if (width > 100) {
                lines++;
                width = widths[ch - 'a'];
            }
        }
        return {lines, width};
    }
};