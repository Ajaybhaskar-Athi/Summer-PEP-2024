//  Single Element in a Sorted Array

/*class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

            int Xor=0;
            for(int i=0;i<nums.size();i++){
                Xor^=nums[i];
            }
            return Xor;
    }
tc=O(n);
    But in lEetcode given to solve it in O(logn )since it is sorted
};*/

#include <bits/stdc++.h>
using namespace std;
// array length is always odd since each element appears twice and a unique element will b be there
// amd pair always exits at even ,odd positions.if even==odd then array is not disturbed u can go to right side of array to check
//  in binary search if we get MID=odd then we r decxreasing mid by 1 since we need to compare even ,odd postions .

// tc=o(logn)

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 1)
            return nums[0];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid & 1)
                mid--;
            if (nums[mid] == nums[mid + 1])
            {
                l = mid + 2;
            }
            else
                r = mid - 1;
        }
        return nums[l];
    }
};

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = -1;

        // left=min it can eat 1 bananan and max it can eat highest bucket KA
        // bananana
        // find maximum bananans in given array;

        int res = 0;
        for (int ele : piles)
            r = max(r, ele);
        while (l <= r)
        {
            int k = l + (r - l) / 2;
            int hour = 0;
            for (int ele : piles)
                hour += ceil(ele / 2);
            if (hour <= h)
            {
                r = k - 1;
                res = hour; // store this and we check if there any possibilty to
                            // have less than this hours koko can eat all bananans
            }
            else
            {
                // means we need to increase the count of bananas it can eat per
                // hour
                l = k + 1;
            }
        }
        return res;
    }
};