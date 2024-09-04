#include<bits/stdc++.h>
using namespace std;

string binary(int num){
    if(num==0)return "0";
    string sr="";
    while(num>0){
        if(num %2 ==1)sr="1"+sr;
        else sr="0"+sr;
        num=num/2;
    }
    return sr;
}

int main(){
    cout<<binary(9);
}

