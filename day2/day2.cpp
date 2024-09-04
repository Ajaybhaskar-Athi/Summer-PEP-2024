#include<bits/stdc++.h>
using namespace std;


//111111111MAX product sub array



// 22222222222//Given x and k where k is sub array sizee , x is a number. find how many times x present in each k sized sub array
//sliding window  

/*int main(){
    int x=2,k=3;
    vector<int>v={2,-1,2,0,0,2,0};
 
        int temp=0;
   
        for(int i=0;i<k;i++){
            if(v[i]==x)temp++;
        }
    
        cout<<temp<<endl;
        for(int i=k;i<v.size();i++){
            if(v[i-k]==x)temp--;
            if(v[i]==x)temp++;
         
            cout<<temp<<endl;
        }
    

}

*/

//(using prefix sum  )

/*int main(){
    int x=2,k=3;
    vector<int>v={2,-1,2,0,0,2,0};
    int n=v.size();
    vector<int>prefix(n);

int c=0;

    for(int i=0;i<n;i++){
        if(v[i]==x){
        prefix[i]=++c;
        }
        else prefix[i]=c;
    }

    int res=prefix[k-1];
    cout<<res<<endl;
    for(int i=k;i<n;i++){
        res=prefix[i]-prefix[i-k];
           cout<<res<<endl;
    }
 

}
*/

// 33333  find max length of substring with unique characters in a given string 

//Longest substring with unique characters

//sliding window 

/*int main(){

    string sr="abbcabdcaabd";
    unordered_set<char>st;
    int l=0,r=0,res=0;
    int n=sr.size();
    while(r<n){
        if(!st.count(sr[r])){
            st.insert(sr[r]);
            r++;
        }

        else{
            st.erase(sr[l]);
            l++;
        }
        res=max(res,r-l);
    }
    cout<<res;
}

*/

//444444444 FInd ALL unique elemennts in an sorted array


/*int main(){
    vector<int>v={1,2,2,3,4,4,5,6,6};
    int c=1,temp=v[0];
    vector<int>res;
    res.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        if(v[i]!=v[i-1])res.push_back(v[i]);
    }
    for(int e:res)cout<<e<<" ";

}
*/


// 5555 find unique elemtns that occur only once in a sorted array 

/*int main(){
    
    vector<int>v={1,2,2,3,4,4,5,6,6};
    vector<int>res;
    
    if(v[0]!=v[1])res.push_back(v[0]);
    for(int i=1;i<v.size()-1;i++){
        if(v[i]!=v[i-1] && v[i]!=v[i+1])res.push_back(v[i]);
    }
    if(v[v.size()-1]!=v[v.size()-2])res.push_back(v[v.size()-1]);
    for(int e:res)cout<<e<<" ";

}
*/

/////6 No of Sub Arrays WHose SUm equals K


int main(){

    vector<int>v={10, 2, -2, -20, 10};
    int n=v.size();
    int k=-10;
    /*//brutforce
        int res=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(sum==k)res++;
        }
    }
    cout<<res;
    Time Complexity : O(n2)
Auxiliary Space: O(1)
*/

    int curSum=0,ans=0;
    map<int,int>prevSum;
    prevSum[0]=1;
    for(int i=0;i<n;i++){
        curSum+=v[i];
        //if currSum-k exists in map  . without if we can directkly write that inside if condituion .if not found in map it gives 0
        if(prevSum.find(curSum-k)!=prevSum.end()){
            ans+=prevSum[curSum-k];
        }
        prevSum[curSum]++;
    }
    cout<<ans;

}