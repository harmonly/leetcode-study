#include <bits/stdc++.h>

#include "trie.cpp"

using namespace std;

class Solution {
   public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        string ans = "";
        sort(words.begin(), words.end(), [&](const string a, const string b) {
            int m = a.length(), n = b.length();
            return m == n ? a > b : m < n;
        });
        unordered_set<string> st;
        st.emplace("");
        for (auto& word : words) {
            if (st.count(word.substr(0, word.size() - 1))) {
                st.emplace(word);
                ans = word;
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (auto& word : words) trie.insert(word);
        string ans = "";
        for (auto& word : words) {
            if (trie.search(word)) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans))
                    ans = word;
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words{"w", "wo", "wor", "worl", "world"};
    cout << Solution2().longestWord(words) << endl;
    return 0;
}