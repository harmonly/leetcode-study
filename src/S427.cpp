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