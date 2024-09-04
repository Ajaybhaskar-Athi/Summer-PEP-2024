#include<bits/stdc++.h>
using namespace std;

    void setOrNot(int num,int k){
        int n2=1<<(k-1);
        cout<<n2<<endl;
        if((num&n2)==0)cout<<"Not Set";
        else cout<<"set";
    }

int main(){
    setOrNot(10,4);
}