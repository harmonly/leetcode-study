#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> visited;
        ListNode *tmp = headA;
        while (tmp != nullptr)
        {
            visited.insert(tmp);
            tmp = tmp->next;
        }
        tmp = headB;
        while (tmp != nullptr)
        {
            if (visited.count(tmp))
                return tmp;
            tmp = tmp->next;
        }

        return nullptr;
    }
};