//leetcode 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&g,vector<vector<int>>&dp){
        int n=g.size(),m=g[0].size();
            if( j<0 || j>=n)return INT_MAX;
            if(i==n-1) return g[i][j];
            if(dp[i][j]!=-1)return dp[i][j];
            int down=  helper(i+1,j,g,dp);
            int dRight=helper(i+1,j+1,g,dp);
            int dLeft=helper(i+1,j-1,g,dp);
                return g[i][j]+ min({down,dRight,dLeft});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {        
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<matrix.size();i++){
            ans=min(ans,helper(0,i,matrix,dp));
        }
        return ans;
    }
};

//tabuilation


class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {        
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int a=j>0?matrix[i-1][j-1]:INT_MAX;
                    int b=matrix[i-1][j];
                    int c= j<n-1? matrix[i-1][j+1]:INT_MAX;
                    matrix[i][j]+=min({a,b,c});
                }
            }
            int ans=INT_MAX;
            for(int j=0;j<n;j++){
                ans=min(ans,matrix[n-1][j]);
            }
            return ans;
        
    }
};


