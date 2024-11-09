//leetcode 3133


#include<bits/stdc++.h>
using namespace std;

/*
If you want B to be greater than A while ensuring A & B = X, here’s how you can approach it:

Set A = X:
This way, A has all the bits of X in the same positions.

Choose B such that it’s greater than A and includes all bits set in X:
Start with B = X, then add additional bits (i.e., bits not in X) to make B greater than A.

One way to ensure B > A:

Find a number Y that has no overlap in bits with X, and add it to B = X | Y. This makes B larger than A while preserving all bits of X in B.

*/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long num=x;
        for(int i=1  ;i<n;i++){
            num= (num+1) | x;
        }
        return num;
    }
};
