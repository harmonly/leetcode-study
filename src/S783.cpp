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
   private:
    int ans = INT_MAX;
    TreeNode *prev = nullptr;

   public:
    int minDiffInBST(TreeNode *root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (prev != nullptr) ans = min(ans, abs(prev->val - root->val));
        prev = root;
        dfs(root->right);
    }
};