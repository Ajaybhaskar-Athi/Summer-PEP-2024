
/*   BRUTFORCE Tc=O(n) same as optimised one BUT it was using an extra space stack


#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        std::stack<int> st;
        ListNode* temp = head;

        // Step 1: Push all node values onto the stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 2: Traverse the list again and compare with stack values
        temp = head;
        while (temp != nullptr) {
            if (temp->val != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};




*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



//Tc=o(n/2)+o(n) 


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

    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*secondHalf=reverse(slow);
        ListNode*temp=head;
          while(secondHalf){ 
            if(temp->val!=secondHalf->val)return false;
            temp=temp->next;
            secondHalf=secondHalf->next;
          }  
          return true;
    }
};