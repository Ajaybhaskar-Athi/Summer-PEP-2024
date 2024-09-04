#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>v,vector<int>&ds,vector<vector<int>>&ans,int idx){
            int n=v.size();
        if(idx==n){
            ans.push_back(ds);
            return;
        }
            ds.push_back(v[idx]);
            helper(v,ds,ans,idx+1);
            ds.pop_back();
            helper(v,ds,ans,idx+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        helper(nums,ds,ans,0);
        return ans;
    }
};




