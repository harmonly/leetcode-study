#include <bits/stdc++.h>

using namespace std;

class Solution {
   private:
    using LL = long long;

   public:
    string toHex(int num) {
        if (num == 0) return "0";
        string ans;
        string hex = "0123456789abcdef";
        LL n = num;
        if (n < 0) n += 0x100000000;
        while (n > 0) {
            ans.push_back(hex[n % 16]);
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int num = -1;
    cout << Solution().toHex(num) << endl;
    return 0;
}