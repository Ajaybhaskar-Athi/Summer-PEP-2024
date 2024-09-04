#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int l=1;
        int h=*max_element(nums.begin(),nums.end());

        int res;
        while(l<=h){
            int mid=l+(h-l)/2; //divisor
            int sum=0;
            for(int i=0;i<nums.size();i++){
             sum += (nums[i] + mid - 1) / mid; //manula cileing function
            }
        
            if(sum<=threshold){
                res=mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return res;
    }
};