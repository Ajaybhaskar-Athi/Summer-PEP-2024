//leetcode 124

//similar to daimeter of binary tree

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxSum=INT_MIN;
    int helper(TreeNode*root){
        if(!root)return 0;
        int leftMax=max(helper(root->left),0);//if theres no left compare with 0;
        int rightMax=max(helper(root->right),0);

        int curr_sum=root->val+leftMax+rightMax;
        maxSum=max(maxSum,curr_sum);

        return root->val+max(leftMax,rightMax);//

    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
