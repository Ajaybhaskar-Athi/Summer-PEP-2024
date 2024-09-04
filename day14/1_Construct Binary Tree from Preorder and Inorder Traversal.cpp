

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
    TreeNode* helper(const vector<int>& pre, unordered_map<int, int>& mp, int start, int end, int& pi) {
        if (start > end) return nullptr;

        int currIdx = mp[pre[pi]];
        TreeNode* root = new TreeNode(pre[pi]);
        pi++;
        
        root->left = helper(pre, mp, start, currIdx - 1, pi);//left sub tree of root presents left to that root in onrder vector
        root->right = helper(pre, mp, currIdx + 1, end, pi);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int pi = 0;
        return helper(preorder, mp, 0, inorder.size() - 1, pi);
    }
};