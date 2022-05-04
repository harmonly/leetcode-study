#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);
        while (q.size() != 1) {
            for (int i = 0; i < k - 1; ++i) {
                int f = q.front();
                q.pop();
                q.push(f);
            }
            q.pop();
        }
        return q.front();
    }
};

class Solution2 {
   public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; ++i) winner = (k + winner - 1) % i + 1;
        return winner;
    }
};