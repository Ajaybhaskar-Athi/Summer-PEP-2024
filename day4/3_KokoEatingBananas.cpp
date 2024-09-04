#include <bits/stdc++.h>
using namespace std;

int minEatingFood(vector<int>piles,int h){
    int r=*max_element(piles.begin(),piles.end());
    //min it can eat k=1 banana per hour and max it can eat the highest banans bucket in  the given array

    for(int k=1;k<=r;k++){
        long long hour=0;
        for(int ele:piles){
            // hour+=ceil(ele/k);
            hour+=(ele+k-1)/k;
        }
        if(hour<=h)return k;
    }
    return r;
    //in these we r checking from eating 1 bananan to hishest bananes ans TC=O(n)*O(n)
    //so we r using below binary search 
}



/*class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = -1;

        // left=min it can eat 1 bananan and max it can eat highest bucket KA
        // bananana
        // find maximum bananans in given array;

        int res = 0;
        for (int ele : piles)
            r = max(r, ele);
        while (l <= r)
        {
            int k = l + (r - l) / 2;
            int hour = 0;
            for (int ele : piles)
                hour += ceil(ele / k);
            cout << hour << endl;
            if (hour <= h)
            {
                r = k - 1;
                res = k; // store this and we check if there any possibilty to
                         // have less than this hours koko can eat all bananans
            }
            else
            {
                // means we need to increase the count of bananas it can eat per
                // hour
                l = k + 1;
            }
        }
        return res;
    }
};
*/
// Tc=O(nlogn)

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = -1;
        int res = 0;
        
        for (int ele : piles)
            r = max(r, ele);

        while (l <= r)
        {
            long long k = l + (r - l) / 2;
            long long hour = 0;
            for (int ele : piles)
                // hour += ceil(ele / k); //it giving wroong op sometimes so write function to calc ciel value
                hour+=(ele+k-1)/k; //this will give u ciel value


            // cout << hour << endl;
            if (hour <= h)
            {
                r = k - 1;
                res = k;
            }
            else
                l = k + 1;
        }
        return res;
    }
};