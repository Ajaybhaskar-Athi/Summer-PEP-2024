//https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;


//Recursion 
int vacation(int i, int j, vector<vector<int>>& nums) {
    int n = nums.size();
    if (i == n) return 0;

    if (j == -1) {
        return max({vacation(i + 1, 0, nums) + nums[i][0], 
                    vacation(i + 1, 1, nums) + nums[i][1], 
                    vacation(i + 1, 2, nums) + nums[i][2]} );
    } else if (j == 0) {
        return max(vacation(i + 1, 1, nums) + nums[i][1], 
                   vacation(i + 1, 2, nums) + nums[i][2]);
    } else if (j == 1) {
        return max(vacation(i + 1, 0, nums) + nums[i][0], 
                   vacation(i + 1, 2, nums) + nums[i][2]);
    } else {
        return max(vacation(i + 1, 0, nums) + nums[i][0], 
                   vacation(i + 1, 1, nums) + nums[i][1]);
    }

}



int main() {
    vector<vector<int>> v = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    cout << vacation(0, -1, v);
    return 0;
}


//Memoisation

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int vacation(int i, int j, vector<vector<int>>& nums) {
    int n = nums.size();
    if (i == n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int res = 0;
    if (j == -1) {
        res = max({vacation(i + 1, 0, nums) + nums[i][0], 
                   vacation(i + 1, 1, nums) + nums[i][1], 
                   vacation(i + 1, 2, nums) + nums[i][2]});
    } else if (j == 0) {
        res = max(vacation(i + 1, 1, nums) + nums[i][1], 
                  vacation(i + 1, 2, nums) + nums[i][2]);
    } else if (j == 1) {
        res = max(vacation(i + 1, 0, nums) + nums[i][0], 
                  vacation(i + 1, 2, nums) + nums[i][2]);
    } else if (j == 2) {
        res = max(vacation(i + 1, 0, nums) + nums[i][0], 
                  vacation(i + 1, 1, nums) + nums[i][1]);
    }

    return dp[i][j] = res;
}

int main() {
    vector<vector<int>> v = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    int n = v.size();
    dp.assign(n, vector<int>(3, -1));

    cout << max({vacation(0, 0, v), vacation(0, 1, v), vacation(0, 2, v)}) << endl;

    return 0;
}




//Tabulation

int main() {
    vector<vector<int>> v = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    int n=v.size();
 vector<vector<int>> dp(n+1, vector<int>(4)); // 
    dp[n][0]=0;
    dp[n][1]=0;
    dp[n][2]=0;
    for(int i=n-1;i>=0;i--){
   dp[i][0]=max(dp[i+1][1]+v[i][1],dp[i+1][2]+v[i][2]);
   dp[i][1]=max(dp[i+1][0]+v[i][0],dp[i+1][2]+v[i][2]);
   dp[i][2]=max(dp[i+1][0]+v[i][0],dp[i+1][1]+v[i][1]);


    }
    return max(dp[0][0],dp[0][1],dp[0][2]);
}

