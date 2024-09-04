//when we r doing entire array product and then finding prime factors it was giving OVERFLOW ERROR 

//find prime factors for individula element and take union of them


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int num,vector<int>&v){
        if(num==1)return;
        for(long long int i=2;i*i<=num;i++){
            while(num%i==0){
                v.push_back(i);
                num=num/i;
            }
        }
        if(num>1)v.push_back(num);
    }

    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>v ;
        for(int ele:nums){
            helper(ele,v);
        }
        unordered_set<int>st;
        for(int ele:v)st.insert(ele);
        return st.size();
    }
};
