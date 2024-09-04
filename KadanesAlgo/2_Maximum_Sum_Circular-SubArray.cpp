/*

To solve the problem of finding the maximum sum of a subarray in a circular array, you need to consider two cases:

The maximum subarray sum is a standard subarray (non-circular).
The maximum subarray sum is a circular subarray, which can be derived by finding the total sum of the array minus the minimum subarray sum.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   void maxSubArray(vector<int>& nums,int& total,int &maxi) {
        int sum=0;
        for(int ele:nums){
            sum+=ele;
             maxi=max(sum,maxi);
            if(sum<0)sum=0;
            total+=ele;
        }   
    }
     int minSubArray(vector<int>& nums) {
        int sum = 0;
        int mini = INT_MAX;
        for (int ele : nums) {
            sum += ele;
            mini = min(sum, mini);
            if (sum > 0) sum = 0;  // Reset sum if it becomes positive
        }
        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi=INT_MIN,total_sum=0;
       maxSubArray(nums,total_sum,maxi);
     int  mini=minSubArray(nums);
     cout<<maxi<<" "<<mini<<" "<<total_sum;
     if(total_sum==mini)return maxi;//all neagtive elements;
      else return max(maxi,total_sum-mini);
           }
};

