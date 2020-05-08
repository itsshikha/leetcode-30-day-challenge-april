/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSumRoot(TreeNode* root){
        if(root == NULL)
            return 0;
        return root->val + max(0,max(maxPathSumRoot(root->left),maxPathSumRoot(root->right)));
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = max(0,maxPathSumRoot(root->left))+max(0,maxPathSumRoot(root->right))+root->val;
        int left = INT_MIN;
        if(root->left)
            left = maxPathSum(root->left);
        int right = INT_MIN;
        if(root->right)
            right = maxPathSum(root->right);
        return max(res,max(left,right));
    }
    
};
