
/*DAY4 13/06/2024


1-> GIven An Array upto certain index it increase and then it decreases. Find the index of peak element in o(logn) complexity
2-> Single Element in a Sorted Array
3->Koko Eating bananas*/
// 4->find duplicate element in an array (we use tortoise and hary for this)

// 1-> GIven An Array upto certain index it increase and then it decreases. Find the index of peak element in o(logn) complexity

#include <bits/stdc++.h>
using namespace std;


int peak(vector<int>v)
{
    int l = 0, r = v.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] < v[mid + 1])
        {
            l = mid + 1;
        }
        else
            r = mid;
    }

    return l;
}

int main()
{
    // vector<int> v = {1, 2, 3, 5, 10, 12, 13, 10, 5, 0};
    vector<int> v = {4, 5, 6, 7, 8, 1, 2};
    int ans = peak(v);
    cout << v[ans];
}