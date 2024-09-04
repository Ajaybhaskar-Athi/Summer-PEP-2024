#include<bits/stdc++.h>
using namespace std;


int countSetBits(int num){
    int count=0;
    if(num==0)return 0;
    while(num>0){
        count+=num&1;
        num=num/2;
    }
    return count;
}

int main(){
   cout<< countSetBits(3);
}