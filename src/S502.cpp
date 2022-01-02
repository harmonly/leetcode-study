#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector<PII> arr;

        for (int i = 0; i < n; ++i) arr.push_back({capital[i], profits[i]});
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            while (curr < n && arr[curr].first <= w)
                pq.push(arr[curr++].second);
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else
                break;
        }
        return w;
    }
};

int main() {
    int k = 2, w = 0;
    vector<int> profits{1, 2, 3};
    vector<int> capital{0, 1, 1};
    cout << Solution().findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}