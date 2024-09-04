#include<bits/stdc++.h>
using namespace std;
int main(){
    //10=1010 and 9=1010
    int a=10,b=9;
    a=a^b;//0011
    b=a^b;//0011 ^ 1001=1010
    //so a shifted to b
    a=a^b;

    cout<<"a:"<<a<<" b: "<<b<<endl;

}