#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool helper(std::stack<char>& stk, std::string sr) {
        for (int i = 0; i < sr.size(); i++) {
            char ch = sr[i];
            
            if (!stk.empty()) {
                char top = stk.top();
                if ((ch == ')' && top == '(') || 
                    (ch == ']' && top == '[') || 
                    (ch == '}' && top == '{')) {
                    stk.pop();
                } else {
                    stk.push(ch);
                }
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }

    bool isValid(std::string s) {
        std::stack<char> stk;
        return helper(stk, s);
    }
};
