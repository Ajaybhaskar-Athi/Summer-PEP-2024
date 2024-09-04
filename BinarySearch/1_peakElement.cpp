//Leetcode 162
    #include<bits/stdc++.h>
    using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(mid==0){
                if(nums[mid]>nums[mid+1])return mid;
                else s=mid+1;//peak must be on the right side 
            }

            else if(mid==n-1){
                if(nums[mid]>nums[mid-1])return mid;
                else e=mid;//mid is greater so mid can be peak or mid is in left halve
            }
            else {
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return  mid;
                else if(nums[mid]>nums[mid+1])e=mid;
                else s=mid+1;
            }
        }



        return -1;
    }
};


//or simply 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;
            // Compare mid element with its right neighbor
            if (nums[mid] > nums[mid + 1]) {
                // Mid is greater than its right neighbor, so peak must be in left part (including mid)
                e = mid;
            } else {
                // Mid is less than its right neighbor, so peak must be in right part
                s = mid + 1;
            }
        }

        // At the end of the while loop, s and e will converge to the peak element
        return s;
    }
};

