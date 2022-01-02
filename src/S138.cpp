#include <bits/stdc++.h>

using namespace std;

/* Definition for a Node.*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;

    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        if (!mp.count(head))
        {
            Node *headNew = new Node(head->val);
            mp[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return mp[head];
    }

    Node *copyRandomList2(Node *head)
    {
        if (!head)
            return nullptr;
        Node *cur = head;
        unordered_map<Node *, Node *> map;
        while (cur)
        {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur)
        {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};