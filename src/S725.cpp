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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            n++;
            tmp = tmp->next;
        }

        int quotient = n / k, remainder = n % k;
        vector<ListNode *> ans(k, nullptr);
        ListNode *curr = head;
        for (int i = 0; i < k && curr; ++i) {
            ListNode *next = new ListNode(curr->val);
            ans[i] = next;
            for (int j = 1; j < quotient + (remainder ? 1 : 0) && curr->next;
                 ++j) {
                curr = curr->next;
                next->next = new ListNode(curr->val);
                next = next->next;
            }
            curr = curr->next;
            remainder = max(remainder - 1, 0);
        }
        return ans;
    }

    vector<ListNode *> splitListToParts2(ListNode *head, int k) {
        int n = 0;
        ListNode *temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        int quotient = n / k, remainder = n % k;

        vector<ListNode *> parts(k, nullptr);
        ListNode *curr = head;
        for (int i = 0; i < k && curr; ++i) {
            parts[i] = curr;
            int partSize = quotient + (i < remainder ? 1 : 0);
            for (int j = 1; j < partSize; ++j) curr = curr->next;
            ListNode *next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        return parts;
    }
};