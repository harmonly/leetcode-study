#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        int a = -1, b = -1;
        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            if (word == word1) {
                if (b != -1) ans = min(ans, i - b);
                a = i;
            } else if (word == word2) {
                if (a != -1) ans = min(ans, i - a);
                b = i;
            }
        }
        return ans;
    }
};