

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


class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        while (head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (!head || !head->next || l == r) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* preLeft = dummy;

        for (int i = 1; i < l; i++) {
            preLeft = preLeft->next;
        }

        ListNode* left = preLeft->next;
        ListNode* right = left;
        for (int i = l; i < r; i++) {
            right = right->next;
        }

        ListNode* nextNode = right->next;
        right->next = nullptr;

        preLeft->next = rev(left);
        left->next = nextNode;

        return dummy->next;
    }
};
