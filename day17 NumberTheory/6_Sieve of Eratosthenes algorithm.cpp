#include<bits/stdc++.h>
using namespace std;

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
    printPrime(36);
}