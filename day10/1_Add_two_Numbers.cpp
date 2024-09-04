/*

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*res=new ListNode(-1);
        ListNode*temp=res;

            int carry=0;
            while(l1 || l2 || carry){ //may be last digits sum will give u carry 1.then u need to add to list even both l1,l2 reaches null
                int sum=0;
                if(l1){
                    sum+=l1->val;
                    l1=l1->next;
                };
                if(l2){
                    sum+=l2->val;
                    l2=l2->next;
                }
                sum+=carry;//add previous carry to current sum
                carry=sum/10;
                ListNode*nn=new ListNode(sum%10);
                temp->next=nn;
                temp=temp->next;
                
            }
            
            return res->next;

    }
};