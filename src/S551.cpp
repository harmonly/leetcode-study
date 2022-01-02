#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for (auto &ch : s) {
            if (ch == 'A')
                if (++A >= 2) return false;

            if (ch == 'L') {
                if (++L >= 3) return false;
            } else
                L = 0;
        }
        return true;
    }
};