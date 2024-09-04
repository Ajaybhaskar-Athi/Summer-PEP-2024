#include<bits/stdc++.h>
using  namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};





class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;
        
        // Step 1: Reverse the linked list
        head = reverse(head);
        
        // Step 2: Process the reversed list to remove nodes
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr != nullptr) {
            if (curr->val < prev->val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        
        // Step 3: Reverse the list again to restore the original order
        head = reverse(head);
        return head;
    }
};


