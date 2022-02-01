#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        string ans;
        unordered_set<char> st;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool ok = true;
                for (auto& ch : s.substr(i, j - i + 1)) st.insert(ch);
                for (auto& ch : s.substr(i, j - i + 1)) {
                    char a = tolower(ch), b = toupper(ch);
                    if (!st.count(a) || !st.count(b)) ok = false;
                }
                if (ok && j - i + 1 > ans.length())
                    ans = s.substr(i, j - i + 1);
                st.clear();
            }
        }
        return ans;
    }

    string longestNiceSubstring2(string s) {
        int n = s.length();
        int maxPos = 0;
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0;
            int upper = 0;
            for (int j = i; j < n; ++j) {
                if (islower(s[j]))
                    lower |= 1 << (s[j] - 'a');
                else
                    upper |= 1 << (s[j] - 'A');
                if (lower == upper && j - i + 1 > maxLen) {
                    maxPos = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(maxPos, maxLen);
    }
};

int main() {
    string s = "Bb";
    cout << Solution().longestNiceSubstring(s) << endl;
    return 0;
}