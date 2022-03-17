#include <bits/stdc++.h>

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


class Trie {
   public:
    Trie() : children(26), isEnd(false) {}

    bool insert(string& word) {
        Trie* node = this;
        for (auto& ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new Trie();
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(string& word) {
        Trie* node = this;
        for (auto& ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr ||
                !node->children[index]->isEnd)
                return false;
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }

   private:
    vector<Trie*> children;
    bool isEnd;
};