
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Merge the two lists find cyclce u will get intersectred node




class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if (!head1 || !head2) return nullptr;

        ListNode* tail = head1;
        while (tail->next) {
            tail = tail->next;
        }

        tail->next = head2;

        ListNode* slow = head1;
        ListNode* fast = head1;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Cycle detected
                slow = head1;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                tail->next = nullptr;
                return slow;  // Intersection point
            }
        }

        // Step 4: Restore the list by removing the link
        tail->next = nullptr;
        return nullptr;  
    }
};
