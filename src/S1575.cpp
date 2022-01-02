#include <bits/stdc++.h>

using namespace std;

class Solution {
   private:
    static constexpr int MOD = 1'000'000'007;
    // f[i][fuel] 代表从位置i出发，当前剩余的油量为fuel的前提下，到达目标位置的[路径数量]
    vector<vector<int>> f;

   public:
    int dfs(const vector<int>& locations, int pos, int finish, int rest) {
        // 如果f中已经有答案，则直接返回
        if (f[pos][rest] != -1) return f[pos][rest];

        // f中没有答案，则路径数量从0开始计算
        f[pos][rest] = 0;
        // 若从当前位置pos无法到达终点finish，返回0
        if (abs(locations[pos] - locations[finish]) > rest) return 0;

        int n = locations.size();
        for (int i = 0; i < n; ++i) {
            // 当前位置不能为原始位置pos
            if (pos != i) {
                int cost = abs(locations[pos] - locations[i]);
                if (cost <= rest) {
                    f[pos][rest] += dfs(locations, i, finish, rest - cost);
                    f[pos][rest] %= MOD;
                }
            }
        }

        // 若pos已经到达终点，则加上该路径
        if (pos == finish) {
            f[pos][rest] += 1;
            f[pos][rest] %= MOD;
        }
        return f[pos][rest];
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // 初始化f
        f.assign(locations.size(), vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }

    int countRoutes2(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        f.assign(n, vector<int>(fuel + 1));
        // 对于本身位置就在目的地的状态，路径数为 1
        for (int i = 0; i <= fuel; ++i) f[finish][i] = 1;

        // 从小到大枚举油量cur,表示剩下的油量rest
        for (int cur = 0; cur <= fuel; ++cur) {
            // i表示初始位置pos
            for (int i = 0; i < n; ++i) {
                if (abs(locations[i] - locations[finish]) > cur)
                    continue;  // 当前油量cur不足以到达终点城市
                // j表示locations中的各位置
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        int cost = abs(locations[i] - locations[j]);
                        if (cur >= cost) {
                            f[i][cur] += f[j][cur - cost];
                            f[i][cur] %= MOD;
                        }
                    }
                }
            }
        }
        return f[start][fuel];
    }
};