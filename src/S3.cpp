#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.length();
        unordered_set<char> st;
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            while (st.find(s[i]) != st.end()) st.erase(s[pre++]);
            st.insert(s[i]);
            ans = max(ans, i - pre + 1);
        }
        return ans;
    }

    int lengthOfLongestSubstring2(string s) {
        int set[128];
        for (int i = 0; i < 128; i++) set[i] = -1;

        int n = s.length();
        int res = 0, start = 0;
        for (int i = 0; i < n; i++) {
            int index = s[i];
            start = max(start, set[index] + 1);
            res = max(res, i - start + 1);
            set[index] = i;
        }
        return res;
    }
};