#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; ++i) fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};