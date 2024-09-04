#include <bits/stdc++.h>
using namespace std;


//using binary concept

void Expo(int a,int b,int m){
    int ans=1;
    while(b>0){
        if(b%2==1){//if odd number last bit is 1
            ans=(ans*a)%m;
        }
        b=b/2;
        a=(a*a)%m;//sqauring it to multiply with next bit if it is set(1);
    }
    cout<<ans;
}

int main(){

    Expo(4,2,3); //4^2=16%3=1
}