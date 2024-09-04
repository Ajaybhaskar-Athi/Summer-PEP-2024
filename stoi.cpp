#include<bits/stdc++.h>
using namespace std;

int main(){
    int*ans=new int[1];
    string sr="101";
    ans[0]=stoi(sr,0,2);//convert string to decimal
    int res=stoi("20",0,10);//convert string to number as it is
cout<<ans[0]<<" "<<res;
}