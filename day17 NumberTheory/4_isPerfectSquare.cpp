/*
1=> for(i= 1->num)i*i=num tc=o(num);
2=> for(i= 1->i*i<=num)i*i=num tc=o(sqrt(num));
3=>Abstarct Bnary search tc=O(logn )
4=> if num has odd no of divisors then it is perfect square 
 

*/


#include<bits/stdc++.h>
using namespace std;

//o(root n);
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i=1;i*i<=num;i++){
            if(i*i==num)return true;
        }
        return false;
    }
};

//o(log n)


class Solution {
public:
    bool isPerfectSquare(int num) {
   int l=1,r=num;
   while(l<=r){
    long long mid=l+(r-l)/2;
    long long sqr=mid*mid;
    if(sqr==num)return true;
    else if(sqr>num)r=mid-1;
    else l=mid+1;
   }
   return false;
    }
};


