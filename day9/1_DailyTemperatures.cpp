//MONotonic Stack

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>stk; //pair.first=value and pair.second=index
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){

         while(!stk.empty() && nums[i]>=stk.top().first){
              stk.pop();
            }

            if(stk.empty())res[i]=0;
             else  res[i]=(stk.top().second-i);
                stk.push({nums[i],i});
            }      
        return res;
    }
};