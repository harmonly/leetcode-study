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
    string tree2str(TreeNode *root) {
        if (!root) return "";
        string ans = to_string(root->val);
        if ((!root->left && !root->right)) return ans;
        ans += "(" + tree2str(root->left) + ")";
        if (root->right) ans += "(" + tree2str(root->right) + ")";
        return ans;
    }
};

class Solution2 {
   public:
    string tree2str(TreeNode *root) {
        string ans = "";
        stack<TreeNode *> st;
        st.push(root);
        unordered_set<TreeNode *> vis;
        while (!st.empty()) {
            auto node = st.top();
            if (vis.count(node)) {
                if (node != root) ans += ")";
                st.pop();
            } else {
                vis.insert(node);
                if (node != root) ans += "(";
                ans += to_string(node->val);
                if (!node->left && node->right) ans += "()";
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
        }
        return ans;
    }
};