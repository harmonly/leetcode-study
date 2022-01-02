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
    int rootSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == targetSum) res++;
        res += rootSum(root->left, targetSum - root->val);
        res += rootSum(root->right, targetSum - root->val);
        return res;
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
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        int res = rootSum(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }

    int pathSum2(TreeNode *root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};