

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
      

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)return head;
        ListNode*temp=head;
        int len=1;
        while(temp->next){
            len++;
            temp=temp->next;
        }

        k=k%len;
        if(k==0 )return head;

        temp=head;
         for(int i=0;i<(len-k)-1;i++){
            temp=temp->next;
         }
            
            ListNode*nextNode=temp->next;
            temp->next=NULL;

            ListNode*end=nextNode;
            while(end->next)end=end->next;
            end->next=head;
            
            return nextNode;

            }
};