#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size(), l = 0;
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (int i = 9; i < n; ++i, ++l) {
            string sub = s.substr(l, i - l + 1);
            if (++cnt[sub] == 2) ans.push_back(sub);
        }
        return ans;
    }

    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    vector<string> findRepeatedDnaSequences2(string s) {
        vector<string> ans;
        int n = s.length();
        if (n <= 10) return ans;
        int x = 0;
        for (int i = 0; i < 9; ++i) x = (x << 2) | bin[s[i]];
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - 10; ++i) {
            x = ((x << 2) | bin[s[i + 9]]) & ((1 << 20) - 1);
            if (++cnt[x] == 2) ans.push_back(s.substr(i, 10));
        }
        return ans;
    }
};

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution().findRepeatedDnaSequences2(s);
    return 0;
}