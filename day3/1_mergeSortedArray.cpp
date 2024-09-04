
/*DAY3 12/06/24

1->Merge Sorted array
2-> Minimum Size Subarray Sum 
3-> given a matrix , xand y values . find sum of all eelemts of x X y sub matrix in given whole matrix (prefix sum)
4-> given a matrix and x1,y1 & x2,y2 . find the sum of matrix covered form both points.
5->Binary Search
6->given a sorted array and element .find the index range where that elemetn lies (BinarySearchII)
*/



/*int main(){
    vector<int>v1={1,2,3,0,0,0};
    vector<int>v2={2,5,6};
    int m=3,n=3;
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(i>=0 && j>=0){
        if(v1[i]>v2[j]){
            v1[k]=v1[i];
            i--;k--;
        }
        else{
            v1[k]=v2[j];
            k--;j--;
        }
    }
    while(j>=0)v1[k--]=v2[j--];
    for(int ele:v1)cout<<ele<<" ";
}
*/