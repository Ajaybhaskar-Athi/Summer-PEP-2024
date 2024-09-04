#include<bits/stdc++.h>
using namespace std;


//Method 1 SLIDING window TEchnique
//TC=O(n)

/*class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
         int sum = 0, j = 0, i = 0, n = nums.size();
        int min_length = INT_MAX;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                min_length = min(min_length, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};
*/



class Solution{
    public :
    vector<int>preSum;

    int minSubArrayLength(int target,vector<int>&nums){

    }
};