#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long maxScore = 0;
    int n, cnt = 0;
    vector<vector<int>> children;

   public:
    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 1; i < n; ++i)
            children[parents[i]].push_back(i);  // children 保存每个节点的子结点
        dfs(0);                                 // 从 0 开始遍历
        return cnt;
    }

    int dfs(int node) {  // dfs 从 0 开始遍历, 返回该节点 + 子节点的个数
        long long score = 1;  // 记录 node 的分数
        int size = 1;         // 保存当前节点及所有子节点的个数
        for (int c : children[node]) {  // 遍历 node 的子结点
            int sz = dfs(c);  // sz 保存子节点 c 及其所有子节点的个数
            score *= sz;  // 分数值 * 子节点 c 及其所有子节点的个数
            size += sz;  // size 保存 子节点 c 及其所有子节点的个数
        }
        if (n - size != 0)
            score *=
                n - size;  // 如果其他位置有节点则 * 其他节点的数量(n - size)
        if (score == maxScore)
            ++cnt;
        else if (score > maxScore) {
            maxScore = score;
            cnt = 1;
        }
        return size;
    }
};