
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// BRUTFORCE o(n) and space complexity =o(n)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        Node *temp = head;
        while (temp)
        {
            Node *nn = new Node(temp->val);
            mp[temp] = nn;
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            Node *copyNode = mp[temp];
            copyNode->next = mp[temp->next];
            copyNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};

//Optimised sc=o(1)
//step 1-> create duplicate in every middle of the nodes in 1st traversal
//step 2-> in 2nd traversal connect random pointers to duplicate nodes
//step 3-> create a dummy node add connect all copied nodes to it and connect next pointers to it


class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node*temp=head;
    while(temp){
        Node* nn = new Node(temp->val);
            nn->next = temp->next;
            temp->next = nn;
            temp = nn->next;
    }
    temp=head;
    while(temp){
        if(!temp->random)temp->next->random=NULL;
        else{
            temp->next->random=temp->random->next; //addding random of copied node to dup random node
        }
        temp=temp->next->next;
    }
    Node*copyNode=new Node(0);
    Node*copyHead=copyNode;
    temp=head;
    while(temp){
        copyNode->next=temp->next; //connect all copy nodes
        temp->next=temp->next->next;//retrive it to orginal list
        copyNode=copyNode->next;
        temp=temp->next;
    }
    return copyHead->next;

    }
};

