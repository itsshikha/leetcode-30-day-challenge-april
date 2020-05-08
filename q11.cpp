/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL || (root->left==NULL&&root->right==NULL))
            return 0;
        return max(2+maxPath(root->left)+maxPath(root->right),max( diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int maxPath(TreeNode* root){
        if(root == NULL)
            return -1;
        if((root->left==NULL&&root->right==NULL))
            return 0;
        return 1+max(maxPath(root->left),maxPath(root->right));
    }
};
