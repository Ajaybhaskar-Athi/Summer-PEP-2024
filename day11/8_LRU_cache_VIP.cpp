#include<bits/stdc++.h>
using namespace std;

class LRUCache {
struct Node{
    int key,value;
    Node*next,*prev;
    Node(int k,int v):key(k),value(v),next(NULL),prev(NULL){}
};

    unordered_map<int,Node*>mp;
    int capacity; 
    Node*head;
    Node*tail;

    void pushToHead(Node*node){
        remove(node);
        add(node);
    }
    void add(Node*node){
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    void remove(Node*node){
        Node*prev=node->prev;
        Node*next=node->next;
        prev->next=next;
        next->prev=prev;
    }

public:
    LRUCache(int capacity):capacity(capacity) {
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
    }
    
    int get(int key) {
     if(mp.find(key)==mp.end())return -1;
     Node*node=mp[key] ;
     pushToHead(node);
     return node->value;  
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*node=mp[key];
            node->value=value;
            pushToHead(node);
        }else{
            if(mp.size()>=capacity){
                Node*LRU=tail->prev;
                mp.erase(LRU->key);
                remove(LRU);
            }
            Node*node=new Node(key,value);
            mp[key]=node;
        add(node);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


