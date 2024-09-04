/*Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  

    bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int len=0;
          string res="";
        for(int i=0;i<n;i++){
            string t="";
            for(int j=i;j<n;j++){
                t+=s[j];
                if(isPalindrome(t)){
                    if(t.length()>len){
                        res=t;
                        len=t.length();
                    }
                }
            }
        }
        return res;    

    }
};

// tc=O(n*3)




class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int xi = 0, xj = 0;
        int ans = 0;

        // Odd length palindromes
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k < n && s[j] == s[k]) {
                j--;
                k++;
            } 
            int len = k - j - 1;
            if (len > ans) {
                xi = j + 1;
                xj = k - 1;
                ans = len;
            }
        }

        // Even length palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                int j = i - 1;
                int k = i + 2;
                while (j >= 0 && k < n && s[j] == s[k]) {
                    j--;
                    k++;
                }
                int len = k - j - 1;
                if (len > ans) {
                    xi = j + 1;
                    xj = k - 1;
                    ans = len;
                }
            }
        }

        return s.substr(xi, ans);
    }
};


// tc=o(n*2);