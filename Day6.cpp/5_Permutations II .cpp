#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void helper(int idx,vector<int>&nums){
        int n=nums.size();
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,int>mp;
            for(int i=idx;i<n;i++){
                if(mp.find(nums[i])!=mp.end())continue;
              else{ 
                mp[nums[i]]++;
                swap(nums[idx],nums[i]);
                helper(idx+1,nums);
                swap(nums[i],nums[idx]);
              }

            }

            }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0,nums);
        return ans;
    }
};
