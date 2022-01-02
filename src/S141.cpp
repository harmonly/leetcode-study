#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

   public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};