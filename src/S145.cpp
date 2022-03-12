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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }

    void postOrder(TreeNode *node, vector<int> &ans) {
        if (!node) return;
        postOrder(node->left, ans);
        postOrder(node->right, ans);
        ans.push_back(node->val);
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            ans.push_back(node->val); 
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};