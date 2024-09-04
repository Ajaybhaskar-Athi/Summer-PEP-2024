



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



//Brutforce using queue

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       queue<pair<int,ListNode*>>q;
       ListNode*temp=head;
       while(temp){
        q.push({0,temp});
        temp=temp->next;
       } 
       ListNode*res=new ListNode(-1);
       temp=res;
       while(!q.empty()){
        pair<int,ListNode*> p=q.front();
            q.pop();
        if(p.first || (!p.first && p.second->val<x)){ //if its already visitred push or if its not visited and its value less then target push
            ListNode*nn=new ListNode(p.second->val);
            res->next=nn;
            res=res->next;
        }
       else q.push({1,p.second});
       }
       return temp->next;
    }
};



//optimised 
//add all less then target first to dummy node and next others




class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
            ListNode*dummy=new ListNode(-1);
            ListNode*ans=dummy;
            ListNode*temp=head;
            while(temp){
                if(temp->val<x){
                    ListNode*nn=new ListNode(temp->val);
                    dummy->next=nn;
                    dummy=dummy->next;
                }
                temp=temp->next;
            }
            temp=head;
            while(temp){
                if(temp->val>=x){
                    dummy->next=new ListNode(temp->val);
                    dummy=dummy->next;
                }
                temp=temp->next;
            }
            return ans->next;

    }
};


