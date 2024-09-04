/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Input : n=2
Output: ["{}{}","{{}}"]
Explanation: This the only two sequences of balanced parenthesis formed using 2 pair of balanced parenthesis.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<string>&res,string sr,int n,int open,int close){
        if(close==n){
            res.push_back(sr);
            return;
        }
        else{
            if(open>close){
                // sr+="}"//dont do this ,coz durig bactracking it will not changed 
                helper(res,sr+')',n,open,close+1);
            }
            if(open<n){
                helper(res,sr+"(",n,open+1,close);
            }
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>v;
        helper(v,"",n,0,0);
        return v;
    }
};