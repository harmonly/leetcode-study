#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root) return false;
        return dfs(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

    /**
     * @brief judge root == subRoot
     *
     * @param root
     * @param subRoot
     * @return true (root == subRoot)
     * @return false (root != subRoot)
     */
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        return root && subRoot && root->val == subRoot->val &&
               dfs(root->left, subRoot->left) &&
               dfs(root->right, subRoot->right);
    }
};