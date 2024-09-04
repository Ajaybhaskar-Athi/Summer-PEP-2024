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



TreeNode*make_level(){
    int n;
    cin>>n;
    queue<TreeNode*>q;
    if(n==-1)return nullptr;
  TreeNode*root=new TreeNode(n);
    q.push(root);
    while(!q.empty()){
       TreeNode*f=q.front();
        q.pop();
        int lc=-1;
        int rc=-1;
        cout<<"Enter Left and Right Childs of "<<f->val<<" ";
        cin>>lc>>rc;
        if(lc!=-1){
          f->left=new TreeNode(lc);
            q.push(f->left);
        }
        if(rc!=-1){
          f->right=new TreeNode(rc);
            q.push(f->right);
        }
        
        
    }
    return root;
}



void allTraversals(TreeNode *root)
{   if(!root) return;
    vector<int> pre, post, in;
    stack<pair<TreeNode *, int>> stk; // root and state ;
    // if we r visiting node 1st time means pre
    // 2nd time means in
    // 3rd time means post
    stk.push({root, 1});
    while (!stk.empty())
    {
        TreeNode *f = stk.top().first;
        int state = stk.top().second;

       if(state==1){
        pre.push_back(f->val);
        stk.top().second++;
      if(f->left) stk.push({f->left,1});
       }
       else if(state==2){
        in.push_back(f->val);
        stk.top().second++;
        if(f->right)stk.push({f->right,1});
       }
       else if(state==3){
        post.push_back(f->val);
        stk.pop();
       }
    }

    cout<<"Pre order: "<<endl;
    for(int ele:pre)cout<<ele<<" ";
    cout<<endl;

      cout<<"In order: "<<endl;
    for(int ele:in)cout<<ele<<" ";
    cout<<endl;

      cout<<"Post order: "<<endl;
    for(int ele:post)cout<<ele<<" ";
    cout<<endl;


}

int main(){
    TreeNode*root=make_level();
    allTraversals(root);
}

//input 
/*

1
Enter Left and Right Childs of 1 2
5
Enter Left and Right Childs of 2 3
4
Enter Left and Right Childs of 5 6
7
Enter Left and Right Childs of 3 -1
-1
Enter Left and Right Childs of 4 -1
-1
Enter Left and Right Childs of 6 -1
-1
Enter Left and Right Childs of 7 -1
-1
*/

//output: 
/*
Pre order:
1 2 3 4 5 6 7
In order:
3 2 4 1 6 5 7
Post order:
3 4 2 6 7 5 1
*/