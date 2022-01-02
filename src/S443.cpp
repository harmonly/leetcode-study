#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) j++;
            int diff = j - i;
            chars[ans++] = chars[i];
            i = j - 1;
            if (diff <= 1) continue;
            int step = 0;
            while (diff > 0) {
                chars[ans++] = diff % 10 + '0';
                diff /= 10;
                step++;
            }
            reverse(chars.begin() + ans - step, chars.begin() + ans);
        }
        return ans;
    }
};