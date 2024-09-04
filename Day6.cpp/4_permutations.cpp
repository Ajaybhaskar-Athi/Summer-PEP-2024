
/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>>res;

    void helper(int idx,vector<int>&sub,vector<bool>&taken,vector<int>&nums){
        int n=nums.size();
        if(idx==n){
            res.push_back(sub);
            return;
        }
      for(int i=0;i<n;i++){
        if(!taken[i]){
            sub.push_back(nums[i]);
            taken[i]=true;
            helper(idx+1,sub,taken,nums);
            sub.pop_back();
            taken[i]=false;
        }
      }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>sub;
        vector<bool>taken(nums.size(),false);
        helper(0,sub,taken,nums);
        return res;
    }
};

// --------------------------------------------------------


class WithoutSpace{
    public:
    vector<vector<int>>ans;
        void helperr(vector<int>arr,int idx){
            int n=arr.size();
            if(idx==n){
                ans.push_back(arr);
                return;
            }

            for(int i=idx;i<n;i++){
                swap(arr[i],arr[idx]);
                helperr(arr,idx+1);
                swap(arr[i],arr[idx]); //to get the array back to its original shape by backtracking 
            }

        }
    vector<vector<int>> permute(vector<int>nums){
        
        helperr( nums,0);
    }
};




///direct in build functuon next_permutation

vector<vector<int>> permute(vector<int>nums){
    sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ans.push_back(nums);
        }
        return ans;
    }