#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = false;
        if (num < 0) num *= -1, neg = true;
        int n = log(num) / log(7);
        int p = (int)pow(7, n);
        string ans = "";
        for (int i = n; i >= 0; --i) {
            if (num < 0) break;
            for (int j = 0; j < 10; ++j) {
                if (num < 0) break;
                if (j * p < num) continue;
                int t = j - (j * p > num);
                ans += to_string(t);
                num -= t * p;
                break;
            }
            p /= 7;
        }
        return neg ? "-" + ans : ans;
    }

    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        if (neg) num *= -1;
        string ans;
        while (num > 0) {
            ans.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};