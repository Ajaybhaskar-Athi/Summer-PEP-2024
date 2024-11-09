#include <bits/stdc++.h>
using namespace std;

void findDivisors(int num)
{
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " "<<endl;
            if (num / i != i)
                cout <<"num/i : "<< num / i << " "<<endl;
        }
    }
}
int main(){
    findDivisors(6);
}