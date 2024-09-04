#include<bits/stdc++.h>
using namespace std;

/*
    a ship can take only its adjacent weights. so leastc apacity it can take =highest elenet of array weights. since if its 
    smaller then any of elemtn we can not able to send it in parts.

    and max wecan send is summ of all weights at once in a ship

*/

class Solution {
public:


    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=INT_MIN,high=0;
        for(int ele:weights){
            low=max(low,ele);
            high+=ele;
        }
        int ans=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2; //capacity
                int sum=0,count=0;
                for(int ele:weights){
                    sum+=ele;
                    if(sum>mid){
                        count++;
                        sum=ele;
                    }
                }
                count++;
                if(count<=days){
                    ans=min(ans,mid);
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }

        }
        return ans;


    }
};