#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;
        if (root->left && root->right) root->left->next = root->right;
        if (root->left && !root->right) root->left->next = dfs(root->next);
        if (root->right) root->right->next = dfs(root->next);
        connect(root->right);
        connect(root->left);
        return root;
    }

    Node* dfs(Node* root) {
        if (!root) return nullptr;
        if (root->left) return root->left;
        if (root->right) return root->right;
        if (root->next) return dfs(root->next);
        return nullptr;
    }
};