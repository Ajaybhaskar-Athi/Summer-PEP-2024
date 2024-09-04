#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

     // Custom comparator to sort numbers to form the largest number
bool static compare(string a, string b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    vector<string> numStrs;
    for (int num : nums) {
        numStrs.push_back(to_string(num));
    }
    
    // Sort numbers using the custom comparator
    sort(numStrs.begin(), numStrs.end(), compare);
    
    // Concatenate sorted numbers to form the largest number
    string result;
    for (string s : numStrs) {
        result += s;
        cout<<s<<" ";
    }
    
    // Handle the case where the largest number is "0"
    if (result[0] == '0') {
        return "0";
    }
    
    return result;
}

};




/*
comperator sorting


Sorting Mechanism
The sorting mechanism does not compare every index i and i+1 directly.
Instead, it uses the custom comparator to determine the order of every pair of strings during the sorting process.
For example, for the input nums = [10, 2], the comparator will compare:
"10" + "2" which is "102"
"2" + "10" which is "210"
Since "210" is greater than "102", "2" should come before "10" in the sorted order.
Example
For the input vector nums = [3, 30, 34, 5, 9]:

Convert to strings: ["3", "30", "34", "5", "9"].
Sort using the comparator:
"3" + "30" = "330", "30" + "3" = "303" => "3" > "30"
"3" + "34" = "334", "34" + "3" = "343" => "34" > "3"
Continue this way for all pairs.
Sorted order: ["9", "5", "34", "3", "30"].
Concatenate: "9534330".
Return "9534330" as the largest number.


*/