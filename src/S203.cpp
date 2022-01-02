#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solutoin
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *H = new ListNode(-1);
        H->next = head;
        ListNode *p = H;

        while (p->next != nullptr)
        {
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }

        return H->next;
    }
};