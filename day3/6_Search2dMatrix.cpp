/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool binarySearch(vector<int>v,int t){
        int l=0,r=v.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(v[mid]==t)return true;
            if(v[mid]>t)r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){;
            if(matrix[i][0]<=target && matrix[i][n-1]>=target)return binarySearch(matrix[i],target);
        }
        return false;
    }
};

