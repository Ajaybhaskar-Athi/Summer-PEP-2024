/*Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 */

#include<bits/stdc++.h>
using namespace std;


/*class Solution {
public:
        vector<vector<string>>ans;

    bool check_palindrome(string t){
        int i=0;
        int j=t.length()-1;
        while(i<j){
            if(t[i]!=t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

        void helper(int idx,vector<string>&vs,string&s){
            int n=s.length();
            if(idx==n){
                ans.push_back(vs);
                return;
            }
            string t="";
            for(int i=idx;i<n;i++){
                t+=s[i];
                if(check_palindrome(t)){
                    vs.push_back(t);
                    helper(i+1,vs,s);
                    vs.pop_back();
                }
            }

        }

    vector<vector<string>> partition(string s) {
            vector<string>vs;
            helper(0,vs,s);
            return ans;
    }
};



*/


#include<bits/stdc++.h>
using namespace std;


class solution{
    public:
    vector<vector<string>>ans;
    bool isPalindrome(string sr){
        int i=0,j=sr.length()-1;
        while(i<=j){
            if(sr[i]!=sr[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(int idx,vector<string>&vs,string sr){

        int n=sr.length();
        if(idx==n){
          ans.push_back(vs);
            return;
        }

        for(int i=idx;i<n;i++){
            string subsr=sr.substr(idx,i-idx+1); //substrring is from index to i 
            if(isPalindrome(subsr)){
                vs.push_back(subsr);
                helper(idx+1,vs,sr);
                vs.pop_back();
            }
        }



    }


      vector<vector<string>> partition(string s) {
            vector<string>vs;
            helper(0,vs,s);
            return ans;
    }


};
int main(){
    solution obj;
    vector<vector<string>>ans=obj.partition("aabb");
        for(auto v:ans){
            for(string ele:v){
                cout<<ele<<"  ";
            }cout<<endl;
        }
}