//we find the divisors of single nUMber But Here Find DIvisors of Evry number in an Array


#include<bits/stdc++.h>
using namespace std;


//if we find divisors individually it takes O(n* root n);

//implent using sieve of eratosthenes//TC=O(n log n)

void printDivisors(vector<int>v){
    int n=*max_element(v.begin(),v.end());
    vector<vector<int>>ans(n+1);
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){ //number itself is also a factor or divisor
            ans[j].push_back(i); //mark all its multiples to i as divisor
        }
    }


    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"-";
        for(int ele: ans[v[i]])cout<<ele<<" ";
        cout<<endl;
    }


}

int main(){
    vector<int>v={3,15,24,36,18};// factors of 3 is ans[3] and factors of 15 is ans[15] and so on
    printDivisors(v);
}