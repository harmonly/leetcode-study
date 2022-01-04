#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2 * n, UNCHECKED)));
        return dfs(graph, dp, 1, 2, 0);
    }

   private:
    const int UNCHECKED = -1;
    const int DRAW = 0;
    const int MOUSE_WIN = 1;
    const int CAT_WIN = 2;
    int n;

    int dfs(vector<vector<int>>& graph, vector<vector<vector<int>>>& dp,
            int mousePos, int catPos, int turns) {
        // 超过节点数两倍,确定为平局
        if (turns >= 2 * graph.size()) return DRAW;

        // dp中有,直接返回
        if (dp[mousePos][catPos][turns] != UNCHECKED)
            return dp[mousePos][catPos][turns];

        // 🐀赢
        if (mousePos == 0) return dp[mousePos][catPos][turns] = MOUSE_WIN;
        // 🐱赢
        if (catPos == mousePos) return dp[mousePos][catPos][turns] = CAT_WIN;

        // turns为偶数是轮到🐀走,为奇数是轮到🐱走
        if (turns % 2 == 0) {
            // 🐀最坏的情况是🐱赢
            int res = CAT_WIN;
            // 尝试走到下一个节点
            for (int nextPos : graph[mousePos]) {
                int nextRes = dfs(graph, dp, nextPos, catPos, turns + 1);
                // 如果🐀可以赢,直接返回
                if (nextRes == MOUSE_WIN)
                    return dp[mousePos][catPos][turns] = MOUSE_WIN;
                // 有平局,先记录为平局,后面如果有🐀可以赢的场景,通过上述语句可以返回
                if (nextRes == DRAW) res = DRAW;
            }
            // 返回🐀走的结果
            return dp[mousePos][catPos][turns] = res;
        } else {
            // 🐱最坏的情况是🐀赢
            int res = MOUSE_WIN;
            for (int nextPos : graph[catPos]) {
                // 🐱不能走到0号节点
                if (nextPos != 0) {
                    // 尝试进入下一个节点
                    int nextRes = dfs(graph, dp, mousePos, nextPos, turns + 1);
                    // 如果🐱可以赢,直接返回
                    if (nextRes == CAT_WIN)
                        return dp[mousePos][catPos][turns] = CAT_WIN;
                    //有平局,先记录为平局,后面如果有🐱可以赢的场景,通过上述语句可以返回
                    if (nextRes == DRAW) res = DRAW;
                }
            }
            // 返回🐱走的结果
            return dp[mousePos][catPos][turns] = res;
        }
    }
};