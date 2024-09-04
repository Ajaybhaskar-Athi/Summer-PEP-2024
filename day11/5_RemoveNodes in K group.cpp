
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node initialization
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;

        while (head) {
            // Check if there are at least k nodes to reverse
            ListNode* KthNode = head;
            for (int i = 1; i < k && KthNode; ++i) {
                KthNode = KthNode->next;
            }
            if (!KthNode) break;

            // Reverse k nodes
            ListNode* nextGroupHead = KthNode->next;
            KthNode->next = nullptr;
            ListNode* newHead = rev(head);

            // Connect reversed k-group to the previous part
            temp->next = newHead;

            // Move temp to the end of the reversed part
            while (temp->next) {
                temp = temp->next;
            }

            // Prepare for the next group
            head = nextGroupHead;
            temp->next = head;
        }

        return dummy->next;
    }
};
