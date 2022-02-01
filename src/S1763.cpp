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
};

int main() {
    string s = "Bb";
    cout << Solution().longestNiceSubstring(s) << endl;
    return 0;
}