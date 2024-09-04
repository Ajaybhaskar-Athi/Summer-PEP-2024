#include<bits/stdc++.h>
using namespace std;


//Recursion

class Solution {
public:
    int helper(int i,int j,int m,int n){
            if(i==m && j==n)return 1;
            if(i>m || j>n)return 0;
        int down=helper(i+1,j,m,n);
        int right=helper(i,j+1,m,n);
        return right+down;
    }
    int uniquePaths(int m, int n) {
        return helper(0,0,m-1,n-1);
    }
};

//Memoisation
 int helper(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i > m || j > n)
            return 0;
        if (i == m && j == n)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = helper(i + 1, j, m, n, dp);
        int right = helper(i, j + 1, m, n, dp);
        return dp[i][j] = right + down;
    }
    


// Tabulation


class Solution {
public:
    int helper(int i,int j,int m,int n){
            if(i==m && j==n)return 1;
            if(i>m || j>n)return 0;
        int down=helper(i+1,j,m,n);
        int right=helper(i,j+1,m,n);
        return right+down;
    }
    int uniquePaths(int m, int n) {
        return helper(0,0,m-1,n-1);
    }
};

