// U r given a vector of vectors . Sort them according to their sum of elemnts. 
// if sum of elemts in one sub vector is greater then other sub vector then 
// the smallest sum vector will come first 

#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
vector<string>ans;
    unordered_set<string>wordset;
    void helper(string sr,int idx,string temp){
        int n=sr.length();
        if(idx==n){
        temp.pop_back();
        ans.push_back(temp);
        return;
        }
    
    for(int i=idx;i<n;i++){
        string subsr=sr.substr(idx,i-idx+1);
        if(wordset.find(subsr)!=wordset.end()){
        helper(sr,idx+1,temp+subsr);

        }
    }


    }
    vector<string> wordSearch(vector<string>dict,string sr){
            wordset=unordered_set<string>(dict.begin(),dict.end());
            helper(sr,0,"");
            return ans;
    }   
};