#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        deque<string> que;
        string ans = "/";
        int n = path.size();
        for (int i = 1; i < n; ++i) {
            if (path[i] == '/') continue;
            string tmp;
            int j = i + 1;
            while (j < n && path[j] != '/') j++;
            tmp = path.substr(i, j - i);
            if (tmp == ".")
                continue;
            else if (tmp == "..") {
                if (!que.empty()) {
                    que.pop_back();
                }
            } else
                que.push_back(tmp);
            i = j;
        }
        while (!que.empty()) {
            ans += que.front() + "/";
            que.pop_front();
        }
        return ans == "/" ? ans : ans.substr(0, ans.length() - 1);
    }
};

int main() {
    string path = "/../";
    cout << Solution().simplifyPath(path) << endl;
    return 0;
}