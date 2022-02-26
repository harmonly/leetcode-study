#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);    // 保存字符的个数
        for (auto& ch : s) freq[ch - 'a']++;
        string ans = "";
        priority_queue<pair<int, int>> q;   // pair<字符, 字符个数>
        for (int i = 25; i >= 0; --i)
            if (freq[i]) q.push(make_pair(i, freq[i])); // 从后往前保存
        while (!q.empty()) {    // 当还有字符则继续
            auto p = q.top();
            q.pop();
            int c = p.first, cnt = p.second;    // 第一个要取的字符
            if (cnt <= repeatLimit) {
                for (int i = 0; i < cnt; ++i) ans += 'a' + c;
            } else {
                for (int i = 0; i < repeatLimit; ++i) ans += 'a' + c;
                if (q.empty())  // 如果已经没有字符则退出
                    break;
                else {
                    auto np = q.top();  // 下一个字符
                    q.pop();
                    int nc = np.first, ncnt = np.second;
                    ans += 'a' + nc;
                    if (--ncnt) q.push(make_pair(nc, ncnt));
                    q.push(make_pair(c, cnt - repeatLimit));
                }
            }
        }
        return ans;
    }
};

int main() {
    cout << Solution().repeatLimitedString("cczazcc", 3) << endl;
    return 0;
}