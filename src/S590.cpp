#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(Node* node, vector<int>& ans) {
        if (!node) return;
        vector<Node*> children = node->children;
        for (int i = 0; i < children.size(); ++i) dfs(children[i], ans);
        ans.push_back(node->val);
    }
};

class Solution2 {
   public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            for (auto& c : node->children) st.push(c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
