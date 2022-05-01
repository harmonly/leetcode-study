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
    void add(TreeNode* root, vector<int>& a) {
        if (!root) return;
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
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        add(root1, a);
        add(root2, a);
        sort(a.begin(), a.end());
        return a;
    }
};

class Solution2 {
   public:
    vector<int> getmid(TreeNode* root) {
        vector<int> a;
        if (!root) return a;
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
        return a;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a = getmid(root1), b = getmid(root2);
        vector<int> ans;
        auto pa = a.begin(), pb = b.begin();
        while (1) {
            if (pa == a.end()) {
                ans.insert(ans.end(), pb, b.end());
                break;
            }
            if (pb == b.end()) {
                ans.insert(ans.end(), pa, a.end());
                break;
            }
            if (*pa < *pb)
                ans.push_back(*pa++);
            else
                ans.push_back(*pb++);
        }
        return ans;
    }
};