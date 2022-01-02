#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int findSecondMinimumValue(TreeNode *root)
    {
        return dfs(root, root->val);
    }

    int dfs(TreeNode *node, int val)
    {
        if (!node)
            return -1;
        if (root->val > val)
            return root->val;
        int left = dfs(node->left, val);
        int right = dfs(node->right, val);
        if (left < 0)
            return right;
        if (right < 0)
            return left;
        return min(left, right);
    }
};