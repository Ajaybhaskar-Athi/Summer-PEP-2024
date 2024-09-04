#include <bits/stdc++.h>
using namespace std;

void findPrimeFactors(int num)
{
    for(int i=2;i<=num;i++){
        while(num %i ==0){
            cout<<i<<" ";
            num=num/i;
        }
    }

}

void FindPrimeFactors(int num){

    for(int i=2;i*i<=num;i++){
        while(num%i==0){
            num=num/i;
            cout<<i<<" ";
        }
    }
    if(num>1)cout<<num; //if given number is prime or in loop the number become prime ,condition failed print it 

}
/*
**After the loop, num has been divided by all its factors up to the square root of the original num. 
**If num is still greater than 1, it means the remaining num is a prime number.
 This can happen in two scenarios: The original num itself is a prime number: 
   1=>In this case, the loop does not execute because there are no divisors other than num itself. 
   2=>The remaining part of num after dividing by smaller factors: For example, for num = 15, the loop will divide by 3 and 5 is left.
    The loop terminates before checking 5.
*/

int main(){
    FindPrimeFactors(60);
}

/*https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/*/