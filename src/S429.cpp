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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        return ans;
    }

    void dfs(Node* node, vector<vector<int>>& ans, int idx) {
        if (!node) return;
        if (ans.size() <= idx) ans.push_back(vector<int>());
        ans[idx].push_back(node->val);
        for (auto& c : node->children) dfs(c, ans, idx + 1);
    }
};

class Solution2 {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        stack<pair<Node*, int>> st;
        st.push(make_pair(root, 0));
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            if (ans.size() <= p.second) ans.push_back(vector<int>());
            ans[p.second].push_back(p.first->val);
            auto children = p.first->children;
            for (auto it = children.rbegin(); it != children.rend(); ++it)
                st.push(make_pair(*it, p.second + 1));
        }
        return ans;
    }
};

class Solution3 {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                for (auto c : node->children) q.push(c);
            }
        }
        return ans;
    }
};