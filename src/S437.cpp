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
   private:
    int count(TreeNode *root, int sum) {
        if (!root) return 0;
        int val = root->val;
        return (val == sum) + count(root->left, sum - val) +
               count(root->right, sum - val);
    }

    using LL = long long;
    unordered_map<LL, int> prefix;

    int dfs(TreeNode *root, LL curr, int targetSum) {
        if (!root) return 0;

        int res = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum)) res = prefix[curr - targetSum];

        prefix[curr]++;
        res += dfs(root->left, curr, targetSum);
        res += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return res;
    }

   public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return count(root, sum) + pathSum(root->left, sum) +
               pathSum(root->right, sum);
    }

    int pathSum2(TreeNode *root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};