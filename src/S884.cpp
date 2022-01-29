#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        string s = s1 + ' ' + s2;
        int n = s.length();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string word;
            int j = i + 1;
            while (j < n && s[j] != ' ') j++;
            word = s.substr(i, j - i);
            mp[word]++;
            i = j;
        }
        for (auto& word : mp) {
            if (word.second == 1) {
                ans.push_back(word.first);
            }
        }
        return ans;
    }
};

int main() {
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    Solution().uncommonFromSentences(s1, s2);
    return 0;
}