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
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        ans.pop_back();
        for (int i = 1; i < ans.size(); ++i)
            if (ans[i] == ans[i - 1]) return false;
        return is_sorted(ans.begin(), ans.end());
    }
};

class Solution2 {
   public:
    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }

    bool dfs(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        int val = root->val;
        if (val <= lower || val >= upper) return false;
        return dfs(root->left, lower, val) && dfs(root->right, val, upper);
    }
};

class Solution3 {
   public:
    bool isValidBST(TreeNode* root) {
        long long inorder = (long long)INT_MIN - 1;
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (root->val <= inorder) return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};