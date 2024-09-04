/*
A multiset in C++ is a type of container provided by the Standard Template Library (STL) that allows you to 
store multiple elements, including duplicates, in a sorted order. Here’s a simple explanation:

Stores Elements: Like other containers, a multiset can hold multiple elements of the same type. (insert)
Allows Duplicates: Unlike a set, which only allows unique elements, a multiset allows multiple instances of the same element.
Sorted Order: The elements in a multiset are automatically stored in a sorted order, typically in ascending order.


erase : set.erase(ele) l;eads to removal of all same ele 's in the set.
thats why use iterators to find the one element only

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int>st;
        vector<int>res;
        for(int i=0;i<k;i++)st.insert(nums[i]);
        res.push_back(*st.rbegin());
        for(int i=k;i<n;i++){
            auto it=st.find(nums[i-k]);
            if(it!=st.end()){
                st.erase(it);
            }
            st.insert(nums[i]);
            if(!st.empty())res.push_back(*st.rbegin());
        }
        return res;
    }
};



//Using Deque by storing maximum elemnts in decreasing order that takes minimum time complexity



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
      deque<pair<int,int>>dq;
      vector<int>res;
      for(int i=0;i<n;i++){
        while(!dq.empty() && nums[i]>=dq.back().first){
            dq.pop_back();
        }
        while(!dq.empty() && dq.front().second<=i-k){
            dq.pop_front();
        }
        dq.push_back({nums[i],i});
        if(i>=k-1)res.push_back(dq.front().first);
      }
      return res;
    }
};


