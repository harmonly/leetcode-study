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

class Solution2 {
    int l[100001], r[100001], size[100001], n;

   public:
    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        for (int i = 1; i < n; ++i) {
            int p = parents[i];
            if (!l[p])
                l[p] = i;
            else
                r[p] = i;
        }
        dfs(0);
        long long maxScore = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int a = 1, b = 1, c = 1;
            if (i != 0) a = n - size[i];
            if (l[i]) b = size[l[i]];
            if (r[i]) c = size[r[i]];
            if (1LL * a * b * c > maxScore)
                maxScore = 1LL * a * b * c, cnt = 1;
            else if (1LL * a * b * c == maxScore)
                ++cnt;
        }
        return cnt;
    }

    void dfs(int x) {
        size[x] = 1;
        if (l[x]) {
            dfs(l[x]);
            size[x] += size[l[x]];
        }
        if (r[x]) {
            dfs(r[x]);
            size[x] += size[r[x]];
        }
    }
};