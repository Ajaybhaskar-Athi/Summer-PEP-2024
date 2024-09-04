#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    //if n=0 or n=1 return that number
    if(n<=1)return n;
    return fib(n-1)+fib(n-2);
    //tc=O(2^n); SC=O(1)
}

//Memoisation (top down ) index n to 0 //Recursive

int fibTD(int n,vector<int>&dp){
    if(n<=1)return dp[n]=n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibTD(n-1,dp)+fibTD(n-2,dp);
    //Tc=o(n) and sc=O(n)
}

//Tabular (bottom up) base case to end //iterative

int fibBU(int n){
    int prev2=0;
    int prev=1;
    if(n<=1)return n;
    for(int i=2;i<=n;i++){
        int t=prev;
        prev+=prev2;
        prev2=t;
    }
    return prev;

    //tc=O(n) and sc=O(1);
}

int main(){
//    cout<< fib(6);
   /* int n=8;
    vector<int>dp(n+1,-1);
    cout<<fibTD(n,dp);*/
    cout<<fibBU(7);
}