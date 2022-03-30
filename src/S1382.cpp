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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            a.push_back(root->val);
            root = root->right;
        }
        a.pop_back();
        return dfs(a, 0, a.size() - 1);
    }

    TreeNode* dfs(vector<int>& a, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(a[mid]);
        node->left = dfs(a, left, mid - 1);
        node->right = dfs(a, mid + 1, right);
        return node;
    }
};