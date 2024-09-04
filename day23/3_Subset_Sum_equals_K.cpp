#include<bits/stdc++.h>
using namespace std;

/*
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
*/
bool helper(int idx,int sum,vector<int>&v,int t){
    if(idx<0){
        if(sum ==t)return true;
        return false;
    }
    int take=helper(idx-1,sum+v[idx],v,t);
    int notTake=helper(idx-1,sum,v,t);
    return take||notTake;
}

int subsetSum(vector<int>&v,int t){
    int n=v.size();
    return helper(n-1,0,v,t);
}

int main(){
    vector<int>v={3, 34, 4, 12, 5, 2};
    bool res=subsetSum(v,61);
    if(res)cout<<"Yes";
    else cout<<"No";
}