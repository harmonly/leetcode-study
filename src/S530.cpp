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
    int getMinimumDifference(TreeNode *root) {
        vector<int> a;
        stack<TreeNode *> st;
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
        int ans = INT_MAX;
        for (int i = 1; i < a.size(); ++i) ans = min(ans, abs(a[i] - a[i - 1]));
        return ans;
    }
};

class Solution2 {
   public:
    int ans = INT_MAX, pre = -1;

    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        if (pre == -1)
            pre = root->val;
        else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right);
    }
};