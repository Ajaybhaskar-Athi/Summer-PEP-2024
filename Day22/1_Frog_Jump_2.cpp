// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;

        int helper(int idx,int k,vector<int>&v){
            if(idx==0){
                return 0;
            }
            int ans=INT_MAX;
            for(int i=1;i<=k;i++){
                if(idx-i>0){
                    int jump=helper(idx-i,k,v)+abs(v[idx]-v[idx-i]);
                    ans=min(ans,jump);
                }
            }
            return ans;
        }

    int frogJump(int k,vector<int>&v){
        int n=v.size();
        return helper(n-1,k,v);
    }
int main(){
    int k=3;
    vector<int>v={10 ,30 ,40 ,50 ,20};
    frogJump(k,v);
}