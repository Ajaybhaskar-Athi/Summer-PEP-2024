


#include<bits/stdc++.h>
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
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next; 
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->val;
        return slow;
    }
    ListNode* mergeTwoSortedLinkedLists(ListNode* h1, ListNode* h2) {
        ListNode* dum = new ListNode(-1);
        ListNode* temp = dum;
        while (h1 && h2) {
            if (h1->val <= h2->val) {
                temp->next = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }
        if (h1)
            temp->next = h1;
        if (h2)
            temp->next = h2;
        return dum->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoSortedLinkedLists(left, right);
    }
};