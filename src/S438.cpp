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
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) return vector<int>();

        vector<int> ans;
        vector<int> cnt(26, 0);
        int diff = 0;

        for (int i = 0; i < pLen; i++) {
            cnt[p[i] - 'a']--;
            cnt[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                diff++;
            }
        }

        if (diff == 0) ans.emplace_back(0);

        for (int i = 0; i < sLen - pLen; i++) {
            if (--cnt[s[i] - 'a'] == 0) {
                diff--;
            } else if (cnt[s[i] - 'a'] == -1) {
                diff++;
            }

            if (++cnt[s[i + pLen] - 'a'] == 0) {
                diff--;
            } else if (cnt[s[i + pLen] - 'a'] == 1) {
                diff++;
            }

            if (diff == 0) ans.emplace_back(i + 1);
        }

        return ans;
    }
};