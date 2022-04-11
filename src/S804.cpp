#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string match[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                            "--.",  "....", "..",   ".---", "-.-",  ".-..",
                            "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--",  "-..-",
                            "-.--", "--.."};
        unordered_set<string> st;
        int ans = 0;
        for (auto& word : words) {
            string s;
            for (auto& ch : word) s += match[ch - 'a'];
            st.insert(s);
        }
        return st.size();
    }
};