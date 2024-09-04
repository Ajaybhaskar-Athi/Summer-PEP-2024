#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
   stack<int>st;
        stack<int>dum;
    MyQueue() {
     

    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.empty())return -1;
        while(!st.empty()){
            dum.push(st.top());
            st.pop();
        }
        int res=dum.top();
        dum.pop();
        while(!dum.empty()){
            st.push(dum.top());
            dum.pop();
        }

        return res;
    }
    
    int peek() {
         if(st.empty())return -1;
        while(!st.empty()){
            dum.push(st.top());
            st.pop();
        }
            int res=dum.top();
        while(!dum.empty()){
            st.push(dum.top());
            dum.pop();
        }

        return res;
    }
    
    bool empty() {
        if(st.empty())return true;
        return false;
    }
};
