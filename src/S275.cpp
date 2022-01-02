#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int left = 0, right = citations.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return n - left;
    }
};

int main()
{
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << Solution().hIndex(citations) << endl;

    return 0;
}