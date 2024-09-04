

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

    TreeNode*helper(vector<int>&post,unordered_map<int,int>&mp,int s,int e,int &pi){
        if(s>e)return NULL;
        int currIdx=mp[post[pi]];
        TreeNode*root=new TreeNode(post[pi]);
        pi--;
        root->right=helper(post,mp,currIdx+1,e,pi); //right sub tree build first since postorder=> root rigth left .as we r moving from last elemtn to backwards we get right sub tree first
        root->left=helper(post,mp,s,currIdx-1,pi);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int pi=n-1;//postorder index;
    return helper(postorder,mp,0,n-1,pi);
      }
};