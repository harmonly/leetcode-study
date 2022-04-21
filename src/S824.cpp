#include <bits/stdc++.h>

using namespace std;

class Solution {
    char vowel[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

   public:
    string toGoatLatin(string sentence) {
        int n = sentence.length();
        string ans;
        string apd;
        for (int i = 0; i < n; ++i) {
            string s;
            int j = i;
            while (j < n && sentence[j] != ' ') s += sentence[j++];
            i = j;
            bool ok = 1;
            for (j = 0; j < 10; ++j)
                if (s[0] == vowel[j]) ok = 0;
            if (ok) {
                s += s[0];
                s.erase(s.begin());
            }
            s += "ma";
            apd += 'a';
            ans += s + apd + " ";
        }
        if (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};