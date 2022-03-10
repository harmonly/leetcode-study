#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    vector<int> preorder2(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            ans.push_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend();
                 ++it)
                st.push(*it);
        }
        return ans;
    }

    void dfs(Node* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        vector<Node*> children = root->children;
        for (int i = 0; i < children.size(); ++i) dfs(children[i], ans);
    }
};