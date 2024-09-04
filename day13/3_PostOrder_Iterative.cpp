
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};


// postorder : left right root 
//im doing root right left so i can reverse it 





class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         if(!root)return {};
        vector<int>v;
        stack<TreeNode*>stk;
      stk.push(root);
      while(!stk.empty()){
        TreeNode*f=stk.top();
            stk.pop();
            v.push_back(f->val); 

            // pushimg left first so that i can get top as right 
            if(f->left)stk.push(f->left);
            if(f->right)stk.push(f->right);
      }
      reverse(v.begin(),v.end());
      return v;
    
    }
};



