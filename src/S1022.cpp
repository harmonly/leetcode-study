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
    int sumRootToLeaf(TreeNode *root) { return dfs(root, 0); }

    int dfs(TreeNode *node, int val) {
        if (!node) return 0;
        val = (val << 1) | node->val;
        if (!node->left && !node->right) return val;
        return dfs(node->left, val) + dfs(node->right, val);
    }
};