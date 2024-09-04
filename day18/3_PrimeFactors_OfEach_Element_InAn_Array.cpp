
#include<bits/stdc++.h>
using namespace std;

//TC=O(n log n);

void findLPF(vector<int>&lpf,vector<int>&prime,int n){
    for(int i=2;i<=n;i++){
        if(prime[i]==1){
            lpf[i]=i;
            for(int j=i*2;j<=n;j+=i){
                prime[j]=0;
                if(lpf[j]==-1)lpf[j]=i;
            }
        }

    }
}

void primeFactors(vector<int>v){
    int n=*max_element(v.begin(),v.end());
    vector<int>prime(n+1,1);
    prime[1]=0;
    vector<int>LPF(n+1,-1);

    findLPF(LPF,prime,n);


    vector<vector<int>>ans(v.size());
    for(int i=0;i<v.size();i++){
        int num=v[i];
        while(num>1){
            ans[i].push_back(LPF[num]);
            num=num/LPF[num];
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" - ";
        for(int ele:ans[i]){
            cout<<ele<<" ";
        }cout<<endl;
    }

}
int main(){
    vector<int>v={15,24,12,36,60};
    primeFactors(v);
}