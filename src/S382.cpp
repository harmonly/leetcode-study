#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    Solution(ListNode *head) { this->head = head; }

    int getRandom() {
        int ans = 0, idx = 0;
        auto p = head;
        while (p) {
            idx++;
            if (rand() % idx == 0) ans = p->val;
            p = p->next;
        }
        return ans;
    }

   private:
    ListNode *head;
};