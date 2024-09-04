
#include <bits/stdc++.h>
using namespace std;




void primeFactors(vector<int>&v){
    int num=*max_element(v.begin(),v.end());
    vector<int>LPF(num+1,-1);
    vector<bool>isPrime(num+1,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=num;i++){
        if(isPrime[i]){
            LPF[i]=i;
            for(int j=i*2;j<=num;j+=i){
                isPrime[j]=false;
                if(LPF[j]==-1)LPF[j]=i;
            }
        }
    }



  
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"-";
        int num=v[i];
        while(num>1){
            cout<<LPF[num]<<" ";
            num=num/LPF[num];
        }
        cout<<endl;
    }
}




int main()

{
    vector<int>v={3,15,24,36,18};
       primeFactors(v);
        // pf(60);
    // primeNumbers(30);
}