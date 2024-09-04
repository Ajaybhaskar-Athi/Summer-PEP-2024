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

void unSetKthBit(int num,int k){
    cout<<"Inittial binary of "<<num<<" : "<<binary(num)<<endl;
    num=num & ~(1<<(k-1));

    cout<<"After un set the  "<<k<<"th bit in  "<<num<<" : "<<binary(num)<<endl;


}

int main(){
    unSetKthBit(9,1);
}
