#include<bits/stdc++.h>
using namespace std;


bool isPrime(int num){
    int flag=0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0)return true;
    return false;

}