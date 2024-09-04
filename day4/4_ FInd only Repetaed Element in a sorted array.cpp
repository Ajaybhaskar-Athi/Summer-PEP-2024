/*Given a sorted array of n elements containing elements in range from 1 to n-1 i.e. one element occurs twice, 
the task is to find the repeating element in an array.
find it in log n complexity.
Examples : 

Input :  arr[] = { 1, 2 , 3 , 4 , 4}
Output :  4

Input :  arr[] = { 1 , 1 , 2 , 3 , 4}
Output :  1*/

#include<bits/stdc++.h>
using namespace std;

// lets observe a sorted array without duplicates {1,2,3,4,5} with indexes {0,1,2,3,4}
// here evry element equals to index+1;
// so if arr[idx]>=idx+1 then left half does not contain any duplicate and it must be in right half.

int findDuplicate(vector<int>v){
    int l=0,r=v.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;

        if((v[mid]==v[mid-1] &&mid>0)||(v[mid]==v[mid+1] && mid<v.size()-1))return v[mid];
        //then dup exists to the right halve
        if(v[mid]>=mid+1){
            l=mid+1;
        }
        else r=mid-1;   
    }
    return -1;
}

int main(){
    vector<int>v={1,1,2,3,4};
    cout<<findDuplicate(v);
}