#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    void deleteNode(ListNode* node) {
        ListNode* pre = node;
        node = node->next;
        while (node && node->next) {
            pre->val = node->val;
            pre = node;
            node = node->next;
        }
        pre->val = node->val;
        pre->next = nullptr;
    }
};