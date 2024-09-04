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

class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *curr = NULL, *prev = NULL;
        while (head)
        {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *temp = dummy;
        while (head)
        {
            ListNode *kthNode = head;
            for (int i = 1; i < k && kthNode; i++)
                kthNode = kthNode->next;
            
            if (!kthNode)break;
            ListNode *NextNode = kthNode->next;
            kthNode->next = NULL;
            while (temp->next)
                temp = temp->next;
            temp->next = rev(head);
            head = NextNode;
        }
        return dummy->next;
    }
};