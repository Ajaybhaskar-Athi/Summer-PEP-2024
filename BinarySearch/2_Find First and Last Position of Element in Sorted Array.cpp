#include<bits/stdc++.h>
using namespace std;
//seperate functions of left bound and right bound

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=BinarySearch(nums,target,true);//Binary Search for Left Bound:
        if(left==-1)return {-1,-1};//target not found
        int right=BinarySearch(nums,target,false);//Bs for Right Bound
        return {left,right};
    }
    int BinarySearch(vector<int>&nums,int t,bool isSearchingLeft){
        int n=nums.size();
        int s=0,e=n-1;
        int idx=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(t>nums[mid])s=mid+1;
            else if(t<nums[mid])e=mid-1;
            else{
                idx=mid;//founded element may be rightbound or left bound,we dont know
                if(isSearchingLeft)e=mid-1;
                else s=mid+1;
            }
        }
        return idx;
    }
};

