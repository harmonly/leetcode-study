#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.length(), ans = 0;
        int t = 0, f = 0;
        int l = 0, r = 0;
        while (r < n) {
            if (s[r] == 'F')
                ++f;
            else
                ++t;
            while (t > k && f > k) {
                if (s[l] == 'F')
                    --f;
                else
                    --t;
                ++l;
            }
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};