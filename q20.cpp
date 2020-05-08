/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return makeBST(preorder,0,preorder.size()-1);
    }
    TreeNode* makeBST(vector<int> preorder, int beg, int end){
        if(beg>end)
            return NULL;
        TreeNode* head = new TreeNode(preorder[beg]);
        int i;
        for(i=beg+1; i<=end; i++){
            if(preorder[i]>head->val)
                break;
        }
        head->left = makeBST(preorder, beg+1, i-1);
        head->right = makeBST(preorder,i,end);
        return head;
        
    }
};
