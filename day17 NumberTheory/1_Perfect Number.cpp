#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findDivisors(int num,int &sum){
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    sum+=i;
                    if(num/i!=i)
                        sum+=num/i;     
            }
            }
    }

    bool checkPerfectNumber(int num) {
        int sum=0;
        findDivisors(num,sum); //num=6,28 ....
        sum-=num;
        if(sum==num)return true;
        return false;
    }
};
