#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
   public:
    vector<int> ops;

    RecentCounter() {}

    int ping(int t) {
        int l = max(t - 3000, 0), r = t;
        ops.push_back(t);
        return upper_bound(ops.begin(), ops.end(), r) -
               lower_bound(ops.begin(), ops.end(), l);
    }
};

class RecentCounter2 {
   public:
    queue<int> q;

    RecentCounter2() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && t - 3000 > q.front()) q.pop();
        return q.size();
    }
};

class RecentCounter3 {
   public:
    int q[10005];
    int l = 0, r = 0;

    RecentCounter3() {}

    int ping(int t) {
        q[r++] = t;
        while (q[l] < t - 3000) ++l;
        return r - l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */