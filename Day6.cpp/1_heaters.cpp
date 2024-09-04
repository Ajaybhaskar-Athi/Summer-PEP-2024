
/*Day6 18/06/2024

1->Heaters 
2->leetcode 22: Generate paranthesis
3->valid paranthesis
4->permutations
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
        // int lowe
    int findRadius(vector<int>& houses, vector<int>& heaters) {
       int res=0;
       sort(heaters.begin(),heaters.end());
       sort(houses.begin(),houses.end());//make sure both houses and heaters are sorted.
       for(int house:houses){
        auto it=upper_bound(heaters.begin(),heaters.end(),house);
          int dist1 = INT_MAX; // Distance to the nearest heater on the right (if exists)
            int dist2 = INT_MAX; // Distance to the nearest heater on the left (if exists)
          
        if(it!=heaters.end()){
            dist1=*it-house;
        }
        if(it!=heaters.begin()){
            it--;//since it sorted the nearest lower bound of house is previous of upper bound only;
            dist2=house-*it;
        }
        int nearest_dist=min(dist1,dist2);
        res=max(res,nearest_dist);
       }
        return res;
    }
};




// #include <iostream>
// #include <vector>
// #include <algorithm> // for std::upper_bound
// using namespace std;
// int main() {
//     int n;cin>>n;
//     vector<int>v(n);
//     for(int i=0;i<n;i++)cin>>v[i];

//     int val=11;
    
//     auto it=upper_bound(v.begin(),v.end(),val);

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
