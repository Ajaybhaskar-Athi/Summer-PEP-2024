#include <bits/stdc++.h>
using namespace std;
//if i do a^b an module with m then it gives overflow error since if a=10 and b=200000 i,a^b gives overflow error. so dont use pow operator


long long expo(int a, int b,int m)
{
    if (b == 0)
        return 1;
    long long k = expo(a, b / 2,m);
    k = (k * k)%m;
        if (b % 2 == 0)
        return k;
    else
        return (k * a)%m;
}

int main()
{

    // (a^b)%m=(a%m X b%m)%m;
    cout << expo(5,2,3);
    return 0;
}