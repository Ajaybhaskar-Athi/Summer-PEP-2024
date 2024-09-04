#include<bits/stdc++.h>
using namespace std;


//IMPlementing all push,pop,top, and finding min eelemnt in a stack in o(1) time complexity

class MinStack {
public:
vector<int>v; //stack
vector<int>minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        if(minStack.empty() ||val<= minStack.back()){
            minStack.push_back(val);
        }
    }
    
    void pop() {
            if(v.size()==0)return;
            if(minStack.back()==v.back()){
                minStack.pop_back();
            }
     v.pop_back();

    }
    
    int top() {
      if(v.size()!=0)return v[v.size()-1];
      return -1;  
    }
    
    int getMin() {
      if(!minStack.empty()){
        return minStack.back();
      }
      return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


