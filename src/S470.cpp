#include <bits/stdc++.h>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        while (true) {
            // rand_X*Y() = (rand_X() - 1) * Y + rand_Y();
            int num =
                (rand7() - 1) * 7 + rand7();  //生成[1, 49]内的等概率随机数
            if (num <= 40) return num % 10 + 1;
        }
    }

    int rand10_2() {
        int first, second;
        while ((first = rand7()) > 6);  // 对[1, 6]采样
        while ((second = rand7()) > 5);  // 对[1, 5]采样
        // first 判断奇偶(1/2概率)
        // 若是奇数 返回second(范围[1, 5])
        // 若是偶数 返回second + 5(范围[6, 10])
        // 上述范围相加后为[1, 10]
        return ((first & 1) ? 0 : 5) + second;
    }
};