#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> st(banned.begin(), banned.end());
        int n = paragraph.length();
        string ans;
        int maxcnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!isalpha(paragraph[i])) continue;
            int j = i;
            string t;
            while (j < n && isalpha(paragraph[j])) t += tolower(paragraph[j++]);
            mp[t]++;
            if (mp[t] > maxcnt && !st.count(t)) {
                maxcnt = mp[t];
                ans = t;
            }
            i = j;
        }
        return ans;
    }
};