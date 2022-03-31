#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            int t = i, ok = 1;
            while (t) {
                if (t % 10 == 0 || i % (t % 10) != 0) {
                    ok = 0;
                    break;
                }
                t /= 10;
            }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};