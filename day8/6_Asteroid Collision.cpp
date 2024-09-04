#include<bits/stdc++.h>
using namespace std;

//simple logic try yoursel;f with drawing directions also ,the logic here is whenver the the element to be pushed is -ve and top elemnt is +ve 
//then they travel in opposite directuions and collison happens


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    

      stack<int>st;
      for(int ele:asteroids){
          bool flag=true;
            if(st.empty())st.push(ele);
            else{
            while(!st.empty()&& ele<0  &&  st.top()>0 ){
                if(abs(ele)==abs(st.top())){
                    st.pop();
                    flag=false;
                    break;
                }
                else if(abs(ele)<abs(st.top()))
                {   flag=false;
                    break;
                }
                else {
                    st.pop();
                }
            }
            if(flag)st.push(ele);
            }
        
      }
       vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    
    }
};

