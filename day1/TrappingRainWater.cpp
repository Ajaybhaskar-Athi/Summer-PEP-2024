#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>v={0,1,0,2,1,0,1,3,2,1,2,1};
int n=v.size();
        vector<int>pre_max(n),suf_max(n);

    pre_max[0]=v[0];

    for(int i=1;i<n;i++){
    pre_max[i]=max(pre_max[i-1],v[i]);
    }

    suf_max[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        suf_max[i]=max(suf_max[i+1],v[i]);
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        ans+=max(0, min(pre_max[i-1],suf_max[i+1])-v[i]);
    }
    cout<<ans<<endl;

}


