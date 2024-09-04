#include<bits/stdc++.h>
using namespace std;

//TC=O(n log n)


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int> temp = nums;
       sort(temp.begin(), temp.end());

       int n = nums.size();
       int s = -1, e = -1;

       for(int i=0; i<n; i++) {
           if(nums[i] != temp[i] && s == -1) s = i; 
           if(nums[n - i - 1] != temp[n - i - 1] && e == -1) e = n - i - 1; 
       }
       
       return s == -1 ? 0 : e - s + 1;
    }
};




//TC=O(n)


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       int Min=INT_MAX,Max=INT_MIN;
       int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                Min=min(Min,nums[i]);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                Max=max(Max,nums[i]);
            }
        }
        int left,right;
        for(left=0;left<n;left++){
            if(nums[left]>Min){
                break;
            }
        }

        for(right=n-1;right>=0;right--){
            if(nums[right]<Max)break;
        }
     // If the subarray is already sorted, return 0
        if (right - left < 0) return 0;

        return right - left + 1;

    }
};


