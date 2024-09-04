#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

void preOrder(TreeNode*root){
    stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode*f=stk.top();
            stk.pop();
            cout<<f->val<<" ";

        // Push right child first so that left child is processed first
            if(f->right)stk.push(f->right);
            if(f->left)stk.push(f->left);
        }
}




