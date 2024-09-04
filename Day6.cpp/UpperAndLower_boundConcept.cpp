// #include <iostream>
// #include <vector>
// #include <algorithm> // for std::upper_bound
// using namespace std;
// int main() {
    
//     std::vector<int> v = {1, 3, 3, 5, 7, 9};

//     int val=9;
    
//     auto it=upper_bound(v.begin(),v.end(),val); //gretaer value nearest to val
// cout<<*(it)<<endl;
//     if(it!=v.end()){
//         cout <<"grater element : "<<*(it)<<endl;
//     }
//     else {
//         cout <<"greater doesnot exist"<<endl;
//     }

//     if(it!=v.begin()){
//         it--;
//         cout <<"smaller "<<*(it)<<endl;
//     }
//     else {
//         cout <<"smaller doesnot exist"<<endl;
//     }

// }
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
vector<int>v = {1,9,8,2,6,5,4};
    
    next_permutation(v.begin(),v.end());//if theres no next gpermutation then it return 1st sorrted permutation
    
  for(int ele:v)cout<<ele<<" ";
    
    return 0;
}



