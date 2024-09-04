// given a number N print lowest prime factor of evry number upto N

// Sieve Approach will be the better one TC=O(n log log n);

#include <bits/stdc++.h>
using namespace std;

void LPFs(int num)
{
    vector<int>LPF(num+1,-1);
    vector<int>prime(num+1,1);
    prime[1]=0;//not prime

    for(int i=2;i<=num;i++){
            if(prime[i]==1){//if its prime
                LPF[i]=i;//LPF of prime Number is NUmber itself
                for(int j=i*2;j<=num;j+=i){
                    prime[j]=0;//it is multiple of i so its not a prime 
                 if(LPF[j]==-1)   LPF[j]=i;//if LPF not marked, mark it  
                }
            }
    }

    for(int i=1;i<=num;i++){
        cout<<LPF[i]<<" ";
    }
}

int main(){
    LPFs(30);
}