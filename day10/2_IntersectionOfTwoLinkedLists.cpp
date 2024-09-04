
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



///

class Solution {
public:
    int getDiff(ListNode*t1,ListNode*t2){
         int len1=0,len2=0;
     while(t1 || t2){
        if(t1){
            len1++;
            t1=t1->next;
        }
        if(t2){
            len2++;
            t2=t2->next;
        }
     }
     return len1-len2;//if diff is -ve then list2 is larger then list1
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    
     int diff=getDiff(head1,head2); 

     if(diff<0){
        while(diff++!=0)head2=head2->next;
     }else while(diff--!=0)head1=head1->next;

        while(head1){
            if(head1==head2)return head1;
            head1=head1->next;
            head2=head2->next;
        }
        return NULL;



    }
};


