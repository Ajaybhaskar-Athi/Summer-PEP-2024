/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

        void helper(vector<int>v,vector<int>&ds,vector<vector<int>>&ans,int sum,int target,int idx){
            int n=v.size();
            if(idx>n || sum>target)return;
            if(idx==n){
                if(sum==target)ans.push_back(ds);
                return;
            }
            ds.push_back(v[idx]);
            sum+=v[idx];
            helper(v,ds,ans,sum,target,idx+1);
            ds.pop_back();
            sum-=v[idx];
               helper(v,ds,ans,sum,target,idx+1);

        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int idx=0,sum=0;
        helper(candidates,ds,ans,sum,target,idx);
        return ans;
    }
};