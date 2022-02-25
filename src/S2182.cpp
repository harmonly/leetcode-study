#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a'] += 1;
        string ans;
        int l = -1;
        while (true) {
            int done = 1;
            int mx = -1;
            for (int i = 25; i >= 0; i -= 1) {
                if (freq[i] && mx == -1) mx = i;
                if (freq[i] && i != l) {
                    l = i;
                    done = 0;
                    break;
                }
            }
            if (done) break;
            int x = min(freq[l], l == mx ? repeatLimit : 1);
            freq[l] -= x;
            for (int j = 0; j < x; j += 1) ans += 'a' + l;
        }
        return ans;
    }
};

int main() {
    cout << Solution().repeatLimitedString("cczazcc", 3) << endl;
    return 0;
}