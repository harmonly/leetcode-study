#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int balancedStringSplit(string s) {
        int ans = 0, d = 0;
        for (char ch : s) {
            ch != 'R' ? ++d : --d;
            if (d == 0) ans++;
        }
        return ans;
    }
};