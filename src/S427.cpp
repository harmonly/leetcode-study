#include <bits/stdc++.h>

using namespace std;

// Definition for a QuadTree node.
class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }

    Node* dfs(vector<vector<int>>& grid, int x, int y, int size) {
        Node* node = new Node();
        int ok = 1;
        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j)
                if (grid[i][j] != grid[x][y]) {
                    ok = 0;
                    break;
                }
        }
        node->val = ok;
        if (ok) {
            node->isLeaf = true;
            node->val = grid[x][y];
        } else {
            node->topLeft = dfs(grid, x, y, size / 2);
            node->topRight = dfs(grid, x, y + size / 2, size / 2);
            node->bottomLeft = dfs(grid, x + size / 2, y, size / 2);
            node->bottomRight = dfs(grid, x + size / 2, y + size / 2, size / 2);
        }
        return node;
    }
};

class Solution2 {
   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
        auto getSum = [&](int x, int y, int size) {
            return pre[x + size][y + size] - pre[x][y + size] - pre[x + size][y] + pre[x][y];
        };
        function<Node *(int, int, int)> dfs = [&](int x, int y, int size) {
            int total = getSum(x, y, size);
            if (total == 0) return new Node(false, true);
            if (total == size * size) return new Node(true, true);
            return new Node(true, false,
                    dfs(x, y, size / 2),
                    dfs(x, y + size / 2, size / 2),
                    dfs(x + size / 2, y, size / 2),
                    dfs(x + size / 2, y + size / 2, size / 2)
            );
        };
        return dfs(0, 0, n);
    }
};