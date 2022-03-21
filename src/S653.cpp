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
    unordered_set<int> st;

   public:
    bool findTarget(TreeNode *root, int k) {
        if (!root) return false;
        int val = root->val;
        if (st.count(k - val)) return true;
        st.insert(val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

class Solution2 {
   public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> st;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (st.count(k - p->val)) return true;
            st.insert(p->val);
            if (p->right) q.push(p->right);
            if (p->left) q.push(p->left);
        }
        return false;
    }
};

class Solution3 {
   public:
    vector<int> vec;

    void inorder(TreeNode *node) {
        if (!node) return;
        inorder(node->left);
        vec.push_back(node->val);
        inorder(node->right);
    }

    bool findTarget(TreeNode *root, int k) {
        inorder(root);
        int l = 0, r = vec.size() - 1;
        while (l < r) {
            int sum = vec[l] + vec[r];
            if (sum == k) return true;
            if (sum < k)
                ++l;
            else
                --r;
        }
        return false;
    }
};