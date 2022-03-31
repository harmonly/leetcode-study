#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        if (val < p->val && val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (val > p->val && val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

class Solution2 {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (1) {
            int val = root->val;
            if (val < p->val && val < q->val)
                root = root->right;
            else if (val > p->val && val > q->val)
                root = root->left;
            else
                break;
        }
        return root;
    }
};