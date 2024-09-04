#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int helper(int idx,vector<int>&h){
        if(idx==0)return h[idx];
        int twoSteps=INT_MAX;
        if(idx-2>0)twoSteps=helper(idx-2,h)+abs(h[idx]-h[idx-2]);
        return min( helper(idx-1,h)+abs(h[idx]-h[idx-1]),twoSteps );
    }

    int frogJump(vector<int>&h){
        int n=h.size();
        return helper(n-1,h);
    }
};