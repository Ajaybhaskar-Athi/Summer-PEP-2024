//Same TO Plainfdriome Partitioning

/*Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 */



#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> ans;
    unordered_set<string> wordSet;

    void helper(int idx, string& s, string current) {
        int n = s.length();
        if (idx == n) {
            current.pop_back(); // Remove the trailing space
            ans.push_back(current);
            return;
        }
        
        string word = "";
        for (int i = idx; i < n; ++i) {
            word += s[i];
            if (wordSet.find(word) != wordSet.end()) {
                helper(i + 1, s, current + word + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        helper(0, s, "");
        return ans;
    }
};








class Solution{
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
        helper(sr,i+1,temp+subsr+" ");

        }
    }


    }
     vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordset = unordered_set<string>(wordDict.begin(), wordDict.end());
        helper(s,0,"");
        return ans;
    }
};