// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> arr = {2, 6, 3, 8, 5};
//     int n = 5;
//     int sum = 0;
//     for (int i = 0; i < (1 << n); i++)
//     {
//         int x = 0;
//         for (int j = 0; j < n; j++)
//             if (i & (1 << j))
//             {
//                 cout << arr[j] << " ";
//                 // cout << 1;
//                 sum += arr[j];
//                 x ^= arr[j];
//             }
//         // else
//         //     cout << 0;
//         cout << endl;
//     }

//     return 0;
// }

//Xor operation 

//SUM OF ALL SUBSETS XOR tools

#include <bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}

for(int i=0;i<(1<<n);i++){
    int value=0;
    for(int j=0;j<n;j++){
        if(i && (1<<j)){
            value=value^v[i];
        }
        else{
            
        }
    }
}

}
