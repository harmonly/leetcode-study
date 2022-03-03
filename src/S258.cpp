#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }

    int addDigits2(int num) { return (num - 1) % 9 + 1; }
};
// 自然数的树根 (num - 1) % 9 + 1;
// 1 * 9 = 9;
// 2 * 9 = 18; -> 1 + 8 = 9
// 3 * 9 = 27; -> 2 + 7 = 9
// 36 -> 3 + 6 = 9
// 45 -> 4 + 5 = 9
// 54 -> 5 + 4 = 9
// 63 -> 6 + 3 = 9
// 72 -> 7 + 2 = 9
// 81 -> 8 + 1 = 9