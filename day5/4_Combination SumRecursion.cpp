#include <bits/stdc++.h>
using namespace std;

/*Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

*/

class Solution
{
public:
    void helper(vector<int> &v, vector<int> &ds, vector<vector<int>> &ans, int target, int sum, int idx)
    {
        int n = v.size();
        if (idx >= n)
            return;
        if (sum > target)
            return;

        if (sum == target)
        { // directly checking sum==target without index==n since we r allowing myltiple elements in a subset
            ans.push_back(ds);
            return;
        }

        ds.push_back(v[idx]);
        sum += v[idx];
        helper(v, ds, ans, target, sum, idx); // to allow multiple elemennts in a sub set like test case 2
        ds.pop_back();
        sum -= v[idx];
        helper(v, ds, ans, target, sum, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0, idx = 0;
        helper(candidates, ds, ans, target, sum, idx);
        return ans;
    }
};