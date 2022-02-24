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
    ListNode *mergeNodes(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        int sum = 0;
        while (fast) {
            if (sum == 0) slow = slow->next;
            if (fast->val == 0) {
                slow->val = sum;
                sum = 0;
            } else
                sum += fast->val;
            fast = fast->next;
        }
        slow->next = nullptr;
        return head->next;
    }
};