
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};



void inOrder(TreeNode*root){
    vector<int>in;
    stack<TreeNode*>stk;
       TreeNode*node=root;
    while(true){
        
        if(node){
            stk.push(node);
            node=node->left;
        }else{ //if node is null;
        if(stk.empty())break;
            node=stk.top();
            stk.pop();
            in.push_back(node->val);
            node=node->right;
        }
    }
    for(int ele:in)cout<<ele<<" ";
}


preorder itertaive , preoorder recursive, post order iterative, post order recursive , inorder iterative , inorder recursive,
A single code to print all pre, post ,inorder , diameter of binary tree , DFs ,BFS 