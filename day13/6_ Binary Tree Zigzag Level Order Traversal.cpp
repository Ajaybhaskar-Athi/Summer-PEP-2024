#include <iostream>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     bool isLeft=true;

     vector<vector<int>>ans;
     if(!root)return ans;

     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty()){
        int levelSize=q.size();
      vector<int>level;     
        for(int i=0;i<levelSize;i++){
        TreeNode*f=q.front();
             q.pop();
            level.push_back(f->val);
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);   
        }
        if(!isLeft){
        reverse(level.begin(),level.end());
        }
            isLeft=!isLeft;
        ans.push_back(level);
     }  
     return ans;
    }
};