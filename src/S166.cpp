#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        long a = numerator, b = denominator;
        if (a % b == 0) return to_string(a / b);
        string ans;
        if (a * b < 0) ans.push_back('-');
        a = abs(a);
        b = abs(b);
        ans += to_string(a / b) + ".";
        a %= b;
        unordered_map<long, int> mp;
        while (a != 0) {
            mp[a] = ans.length();
            a *= 10;
            ans.push_back(a / b + '0');
            a %= b;
            if (mp.count(a)) {
                int val = mp[a];
                ans.insert(ans.begin() + val, '(');
                ans.push_back(')');
                return ans;
            }
        }
        return ans;
    }
};