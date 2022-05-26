#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        int prior[26];
        for (int i = 0; i < 26; ++i) prior[order[i] - 'a'] = i;
        for (int k = 1; k < words.size(); ++k) {
            string &a = words[k - 1], &b = words[k];
            int la = a.length(), lb = b.length();
            int i = 0, j = 0;
            while (i < la && j < lb) {
                if (prior[a[i] - 'a'] < prior[b[j] - 'a'])
                    break;
                else if (prior[a[i] - 'a'] > prior[b[j] - 'a'])
                    return false;
                ++i, ++j;
            }
            if (i != la && j == lb) return false;
        }
        return true;
    }
};