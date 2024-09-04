



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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev=dummy;
         while(head){
            bool dup=false;
            while(head->next && head->val==head->next->val){
                dup=true;
                head=head->next;
            }
            if(dup){
                //if duplictae present skip current elemnt as well
                head=head->next;
                continue;//means we r not executing below steps
            }
            prev->next=head;
            prev=head;
            head=head->next;
         }

        prev->next=nullptr;
        return dummy->next;

    }
};