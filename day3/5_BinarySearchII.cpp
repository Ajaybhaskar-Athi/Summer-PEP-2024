/*given array and element ,there are multiple such elements present in the array.
and array is sorted  return the range if indexes where elemetns present

test case 1: v={1,2,3,3,4,4,4,5,10,11,12};
k=4 so output=(4,6);
*/

#include <bits/stdc++.h>
using namespace std;

int LeftMost(vector<int> v, int n, int k)
{

    int l = 0, r = n - 1;
    int leftIdx = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (k == v[mid])
        {
            leftIdx = mid;
            r = mid - 1;
        }
        else if (k > v[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return leftIdx;
}

int rightMost(vector<int> v, int n, int k)
{
    int l = 0, r = n - 1;
    int rightIdx = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (k == v[mid])
        {
            rightIdx = mid;
            l = mid + 1;
        }

        else if (k > v[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return rightIdx;
}

int main()
{
    vector<int> v = {1, 2, 3, 3, 4, 4, 4, 5, 10};
    // vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4, 4, 5, 5};
    int left = LeftMost(v, v.size(), 3);
    int right = rightMost(v, v.size(), 3);
    cout << "The Range is " << left << " " << right;
}