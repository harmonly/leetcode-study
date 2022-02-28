#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) return vector<int>();

        vector<int> ans;

        vector<int> scnt(26);
        vector<int> pcnt(26);

        for (int i = 0; i < pLen; i++) {
            scnt[s[i] - 'a']++;
            pcnt[p[i] - 'a']++;
        }

        if (scnt == pcnt) ans.emplace_back(0);

        for (int i = 0; i < sLen - pLen; i++) {
            scnt[s[i] - 'a']--;
            scnt[s[i + pLen] - 'a']++;
            if (scnt == pcnt) ans.emplace_back(i + 1);
        }

        return ans;
    }

    vector<int> findAnagrams2(string s, string p) {
        int m = s.length(), n = p.length();
        int cnt[26], diff = 0;
        vector<int> ans;
        if (n > m) return ans;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++, cnt[p[i] - 'a']--;
        for (int i = 0; i < 26; ++i) diff += cnt[i] != 0;
        if (diff == 0) ans.emplace_back(0);
        for (int i = n; i < m; ++i) {
            diff += -(cnt[s[i - n] - 'a'] == 1) + (cnt[s[i - n] - 'a'] == 0);
            --cnt[s[i - n] - 'a'];
            diff += -(cnt[s[i] - 'a'] == -1) + (cnt[s[i] - 'a'] == 0);
            ++cnt[s[i] - 'a'];
            if (diff == 0) ans.emplace_back(i - n + 1);
        }
        return ans;
    }
};