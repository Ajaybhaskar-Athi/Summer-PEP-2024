/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
            // Refer PEP noteBOOK
          /*  //Brutforce
            int sum=0,count=0;
            while(sum+divisor<=dividend){
                count++;
                sum+=divisor;
            }
            return count;

        tc=O(dividend);
        suppose if dividend=INT_MAX=2^31-1 and divisor =1 it needs to add this 1 by 2^31-1 times which gives u time exceeded error
            */

            if(dividend==divisor)return 1;
            bool sign=true;
            if(dividend<0 && divisor>0)sign=false;
            if(dividend>0 && divisor<0)sign=false;
            /*int n=abs(dividend); 
            coz if numerator is -ve we r making it to +ve BUT if dividend= -2^31 its abs(-2^31)=2^31 which was not stored in INT 
            type as its max value is 2^31-1 so use long data type here;*/
            long n=abs(dividend);
            long d=abs(divisor);
            int quotient=0;
            while(n>=d){
                int cnt=0;
                while(n>=(d<<(cnt+1))){ //d<<(cnt+1)=d*2^(cnt+1) checking for divosr X 2^number is satisfying or not
                cnt++;
               
                }
                quotient+=1<<cnt; //1<<cnt=2^cnt
                 n=n-(d<<cnt); 
            }
            if(quotient==(1<<31) && sign)return INT_MAX;
            if(quotient==(1<<31) && !sign)return INT_MIN;
            return sign?quotient:-quotient;

    }
};