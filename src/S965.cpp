#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isUnivalTree(TreeNode *root) {
        if (!root) return true;
        int val = root->val;
        return dfs(root, val);
    }

    bool dfs(TreeNode *node, int val) {
        if (!node) return true;
        if (node->val != val) return false;
        return dfs(node->left, val) && dfs(node->right, val);
    }
};

class Solution2 {
   public:
    bool isUnivalTree(TreeNode *root) {
        if (!root) return true;
        int val = root->val;
        stack<TreeNode *> sta;
        sta.push(root);
        while (!sta.empty()) {
            auto node = sta.top();
            sta.pop();
            if (node->val != val) return false;
            if (node->right) sta.push(node->right);
            if (node->left) sta.push(node->left);
        }
        return true;
    }
};