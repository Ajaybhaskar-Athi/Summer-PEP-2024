#include<bits/stdc++.h>
using namespace std;
//N=6 op:2,3,5 (prime Numbers less then N)


/*
bool check(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int primeNumbers(int num){

    for(int i=1;i<=num;i++){
        if(check(i)){
            cout<<i<<" ";
        }
    }
    TC=O(n* root n);

}

*/

//Sieve of Eratosthenes algorithm 


void printPrime(int num)
{
    if(num<=2){
        cout<<"No Prime Numbers Upto LEss then "<<num<<endl;
        return;
    }

    vector<bool>isPrime(num+1,true);
    
    isPrime[0]=false,isPrime[1]=false;//0 and 1 are not primes
    for(int i=2;i<=num;i++){
        if(isPrime[i]){
            //mark all its multipliers to not primes
            for(int j=i*i;j<=num;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<=num;i++){
            if(isPrime[i])cout<<i<<" ";
    }
}

int main(){
    printPrime(12);
}