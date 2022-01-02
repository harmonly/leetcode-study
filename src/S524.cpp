#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string a, string b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });
        for (auto& str : dictionary) {
            for (int i = 0, j = 0; i < s.size(); ++i) {
                j += (s[i] == str[j]);
                if (j == str.size()) return str;
            }
        }
        return "";
    }
};