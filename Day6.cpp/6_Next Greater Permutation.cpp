#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*int main() {
    int arr[] = {3,2,1};
    
    next_permutation(arr,arr+3);//if theres no next gpermutation then it return false and array not changed
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

*/



class Solution {
public:
    void rev(vector<int>&nums,int s,int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }


    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
       int idx=-1;//breakpoint 
       for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
       }
        if(idx==-1){ //if its in descending order 
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=idx;i--){ //find closest one larger then break point 
                if(nums[i]>nums[idx]){
                    swap(nums[i],nums[idx]);
                    break;
                }
        }
        rev(nums,idx+1,n-1);



           
    }
};





