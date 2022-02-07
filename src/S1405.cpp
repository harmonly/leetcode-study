#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) pq.push(make_pair(a, 'a'));
        if (b) pq.push(make_pair(b, 'b'));
        if (c) pq.push(make_pair(c, 'c'));
        string ans = "";
        while (!pq.empty()) {
            auto fp = pq.top();
            pq.pop();
            if (ans.size() >= 2 && fp.second == ans.back() &&
                fp.second == ans[ans.size() - 2]) {
                if (pq.empty()) break;
                auto sp = pq.top();
                pq.pop();
                ans += sp.second;
                --sp.first;
                if (sp.first) pq.push(sp);
                pq.push(fp);
            } else {
                ans += fp.second;
                --fp.first;
                if (fp.first) pq.push(fp);
            }
        }
        return ans;
    }
};

int main() {
    cout << Solution().longestDiverseString(7, 1, 0) << endl;
    return 0;
}