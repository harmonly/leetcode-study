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
    vector<int> in, post;
    unordered_map<int, int> mp;

    TreeNode* build(int in_left, int in_right, int post_left, int post_right) {
        if (post_left > post_right) return nullptr;
        int in_root = mp[post[post_right]];
        TreeNode* root = new TreeNode(in[in_root]);
        int right_size = in_right - in_root;
        root->left =
            build(in_left, in_root - 1, post_left, post_right - right_size - 1);
        root->right = build(in_root + 1, in_right, post_right - right_size,
                            post_right - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        in = inorder;
        post = postorder;
        for (int i = 0; i < n; ++i) mp[in[i]] = i;
        return build(0, n - 1, 0, n - 1);
    }
};