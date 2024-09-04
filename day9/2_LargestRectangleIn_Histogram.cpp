#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n); //leftmin and rightmin
        stack<pair<int,int>>stk; //first=heights and  second=index

        for(int i=0;i<n;i++){
            while(!stk.empty() && nums[i]<=stk.top().first){
                stk.pop();
            }
            if(stk.empty())left[i]=-1;
           else left[i]=stk.top().second;
            stk.push({nums[i],i});
        }

        while(!stk.empty())stk.pop();

        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&& nums[i]<=stk.top().first){
                stk.pop();
            }
            if(stk.empty())right[i]=n;
            else right[i]=stk.top().second;
            stk.push({nums[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]*(right[i]-left[i]-1));
        }
        return ans;


    }
};