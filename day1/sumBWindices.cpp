#include<bits/stdc++.h>
using namespace std;


//Sum b/w indices


/*int main(){


    vector<int>v={2,3,4,5,6,7};

    int l=2;
    int r=2;
    int sum=0;
    for(int i=l;i<=r;i++){
        sum+=v[i];
    }
    cout<<sum;


    
    
}*/
// 2222222222222222
/*
// Given a main array arr and two additional arrays l and r of the same length, where each element in l and r represents an index in arr such that l[i] <= r[i],
//  your task is to find the sum of elements in the main array between the indices l[i] and r[i] (inclusive) for each i


int main(){
    vector<int>v={2,3,4,5,6,7};
    vector<int>l={5,1,3,0,2};
    vector<int>r={5,2,4,1,4};
    int q=l.size(); // l,r are having same size

        for(int i=0;i<q;i++ ){
            int start=l[i];
            int end=r[i];
            int sum=0;
            for(int j=start;j<=end;j++){
                sum+=v[j];
            }
            cout<<sum<<endl;
        }


}

*/


//Above With Prefix Sum



int main(){
 vector<int>v={2,3,4,5,6,7};
    vector<int>l={5,1,3,0,2};
    vector<int>r={5,2,4,1,4};
    int q=l.size();


    vector<int>pref_sum(v.size());
    pref_sum[0]=v[0];
    for(int i=1;i<v.size();i++){
        pref_sum[i]=pref_sum[i-1]+v[i];
    }

    for(int i=0;i<q;i++){
        cout<<pref_sum[r[i]]-( l[i]-1>=0 ?pref_sum[l[i]-1]:0 );
    }
}