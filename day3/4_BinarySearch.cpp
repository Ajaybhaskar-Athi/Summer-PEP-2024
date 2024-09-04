#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>v,int n,int k){

   
   int l=0,r=n-1;
  
   while(l<=r){
     int mid=(l+r)>>1;
    if(v[mid]==k)return mid;
    if(k>v[mid])l=mid+1;
    else r=mid-1;
   }
    return -1;
}
int main(){
    vector<int>v={2,7,10,12,13};
    int res=bs(v,v.size(),2);
    cout<<res;
}