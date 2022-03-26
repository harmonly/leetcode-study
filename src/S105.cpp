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
    int n;
    vector<int> pre, in;
    unordered_map<int, int> mp;

    TreeNode* build(int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right) return nullptr;
        int in_root = mp[pre[pre_left]];
        TreeNode* root = new TreeNode(in[in_root]);
        int left_size = in_root - in_left;
        root->left =
            build(pre_left + 1, pre_left + left_size, in_left, in_root - 1);
        root->right =
            build(pre_left + left_size + 1, pre_right, in_root + 1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        pre = preorder;
        in = inorder;
        for (int i = 0; i < n; ++i) mp[in[i]] = i;
        return build(0, n - 1, 0, n - 1);
    }
};