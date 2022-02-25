#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string complexNumberMultiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        int a = 0, b = 0, c = 0, d = 0;
        int i = 0;
        while (i < m && num1[i] != '+') ++i;
        a = stoi(num1.substr(0, i));
        b = stoi(num1.substr(i + 1, m - i - 2));
        i = 0;
        while (i < n && num2[i] != '+') ++i;
        c = stoi(num2.substr(0, i));
        d = stoi(num2.substr(i + 1, n - i - 2));
        string ans = "";
        ans += to_string(a * c - b * d) + "+";
        ans += to_string(a * d + c * b) + "i";
        return ans;
    }

    string complexNumberMultiply2(string num1, string num2) {
        int a, b, c, d;
        sscanf(num1.c_str(), "%d+%di", &a, &b);
        sscanf(num2.c_str(), "%d+%di", &c, &d);
        return to_string(a * c - b * d) + "+" + to_string(a * d + c * b) + "i";
    }
};

int main() {
    cout << Solution().complexNumberMultiply("78+-76i", "-86+72i") << endl;
    return 0;
}