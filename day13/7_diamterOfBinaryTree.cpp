//similar to Binary tree maximum path sum

#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.

class TreeNode
{
public:
    int val;
 TreeNode*left;
  TreeNode *right;
 TreeNode(int d) : val(d), left(NULL), right(NULL) {}
};



class Solution {
public:
    int res=INT_MIN;
    int helper(TreeNode*root){
        if(!root)return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        int curr=left+right;
        res=max(res,curr);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res;
    }
};
