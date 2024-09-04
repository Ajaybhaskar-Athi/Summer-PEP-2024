/*Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1*/



/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int bi=0;bi<=31;bi++){ //bi=bit index
            int count=0;
            for(int i=0;i<n;i++){
                if((nums[i] & (1<<bi)))count++;
            }
            if(count %3==1){
                ans=ans | (1<<bi);
            }
        }
        return ans;
    }
};


tc=0(n*32) in every case ven if number takes 4 bits we r iterating entire 32 bitss
sc=0(1);
*/




