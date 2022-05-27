#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26);
        for (auto& c : magazine) cnt[c - 'a']++;
        for (auto& c : ransomNote)
            if (cnt[c - 'a']-- == 0) return false;
        return true;
    }
};