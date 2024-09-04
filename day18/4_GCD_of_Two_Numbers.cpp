
#include<bits/stdc++.h>
using namespace std;

//TC=O(log(min(a,b)));

int gcd(int a,int b){
    if(a==0)return b;
    gcd(b%a,a);
}

int main(){
    cout<<gcd(24,36);
    //no matter that a is smaller and b is larger 
    //suppose a=36 and b=24 in 1st iteration b%a=24%36=24 so it call gcd(24,36) , it will swap no issue;
}