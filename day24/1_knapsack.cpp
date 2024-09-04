
/*
Problem Statement: You are given two arrays, weights and val, of length n, where: weights[i] represents the weight of the i-th item.
 val[i] represents the value of the i-th item. You are also given a positive integer amount
 , which represents the maximum weight capacity of a knapsack.
  You need to determine the maximum value you can achieve by selecting a subset of the items 
  such that the total weight does not exceed the given capacity amount.
   You can either include an item or exclude it from the knapsack, but you cannot take fractions of an item.
*/

#include<bits/stdc++.h>
using namespace std;
    class solution{
        public:
            int helper(int idx,int sum,int t,vector<int>&w,vector<int>&val){
                if(idx<0)return 0;
                if(sum>t)return INT_MIN;
                int notTake=helper(idx-1,sum,t,w,val);
                int take=helper(idx-1,sum+w[idx],t,w,val)+val[idx];
                return max(take,notTake);

            }

        int maxAmount(vector<int>&weights,vector<int>&val,int amount){
            int n=weights.size();
            return helper(n-1,0,amount,weights,val);
        }
    };