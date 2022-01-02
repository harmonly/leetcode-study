#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() { this->word = ""; }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c : word) {
        if (!node->children.count(c)) node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
   private:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root,
             set<string>& res) {
        char ch = board[x][y];
        if (!root->children.count(ch)) return;
        root = root->children[ch];
        if (root->word.size() > 0) res.insert(root->word);

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int dx = x + dirs[i][0];
            int dy = y + dirs[i][1];
            if (dx >= 0 && dx < board.size() && dy >= 0 &&
                dy < board[0].size()) {
                if (board[dx][dy] != '#') dfs(board, dx, dy, root, res);
            }
        }
        board[x][y] = ch;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto& word : words) insertTrie(root, word);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, root, res);
        }

        for (auto& word : res) ans.emplace_back(word);
        return ans;
    }
};